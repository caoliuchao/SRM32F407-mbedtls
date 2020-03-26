/********************************************************************************
 * @�汾  ��V1.0
 * @�ļ�  : sysbsp.c
 * @����  : caochao
 * @����  : 9-19-2018
 * @�汾  : version1.0
 * @��λ  : �������ӿƼ���ѧ
 * @ժҪ  : ���C�ļ�ʱӲ���ĳ�ʼ��
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 
 ********************************************************************************/
#include "stm32f4xx.h"
#include "includes.h"
#include "sysbsp.h"

/********************************************************************************
 *  ������:  BSP_Init
 *  ��  ��:  ϵͳӲ���ĳ�ʼ��
 *  ��  ��:   
 *           ��
 *  ��  ��:   
 *           true����ʼ���ɹ�
 *          false����ʼ��ʧ��
 ********************************************************************************/
bool SYSBSP_Init(void)
{ 
    int i;
    size_t outlen;
    size_t olen = 0;
    size_t tempLen = 0;
    
    const mbedtls_cipher_info_t* info;
    mbedtls_cipher_context_t cipher_ctx;
    
    unsigned char iv[16];   //iv
    unsigned char key[16] = "CBCPASSWD1234"; //��Կ��ֵ
   
    unsigned char cipher[100]={0}; //���Ŀռ�
    unsigned char dec_plain[100]={0}; //���ܺ����ĵĿռ�
    unsigned char plain[16] = "ZhangShiSan!!!!"; //���Ŀռ�
    
    /*��ʼ������*/
    USART1_Configuration();
    
    mbedtls_cipher_init(&cipher_ctx);
    info = mbedtls_cipher_info_from_type(MBEDTLS_CIPHER_AES_128_CBC);
    printf("\n  cipher info setup, name: %s, block size: %d\r\n", 
           mbedtls_cipher_get_name(&cipher_ctx),mbedtls_cipher_get_block_size(&cipher_ctx));
    
    mbedtls_cipher_setup(&cipher_ctx,info);
    mbedtls_cipher_setkey(&cipher_ctx,key, 128,MBEDTLS_ENCRYPT);
    mbedtls_cipher_set_iv(&cipher_ctx,iv,16);
    
    mbedtls_cipher_update(&cipher_ctx,plain,16,cipher,&outlen);
    olen = olen + outlen;
    
    mbedtls_cipher_update(&cipher_ctx,plain,16,cipher+olen,&outlen);
    olen = olen + outlen;
    
    mbedtls_cipher_update(&cipher_ctx,plain,16,cipher+olen,&outlen);
    olen = olen + outlen;
    
    mbedtls_cipher_finish(&cipher_ctx,cipher+olen,&outlen);
    olen = olen + outlen;
     
    mbedtls_cipher_free(&cipher_ctx);
   
    mbedtls_cipher_init(&cipher_ctx);
    info = mbedtls_cipher_info_from_type(MBEDTLS_CIPHER_AES_128_CBC);
    mbedtls_cipher_setup(&cipher_ctx,info);
    mbedtls_cipher_setkey(&cipher_ctx,key, 128,MBEDTLS_DECRYPT);
    mbedtls_cipher_set_iv(&cipher_ctx,iv,16);
    
    mbedtls_cipher_update(&cipher_ctx,cipher,olen,dec_plain,&outlen);
    tempLen = tempLen + outlen;
 
    mbedtls_cipher_finish(&cipher_ctx,dec_plain+tempLen,&outlen);
    tempLen = tempLen + outlen;
    
    mbedtls_cipher_free(&cipher_ctx);
    
    for (i = 0; i < tempLen; i++)
    {
        printf("%c",dec_plain[i]);
    }
    
    printf("\r\n");
    
    return true;
}
/**************************************�ļ�����*************************************/

