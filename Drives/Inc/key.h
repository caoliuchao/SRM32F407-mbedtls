/*************************************************************************************
 * @文件  : key.h
 * @作者  : caochao
 * @日期  : 22-9-2017
 * @摘要  : 这个C文件时实现按键以及中断的函数声明
 *
 * 修改人 :
 *  日期  :
 *
 * 修改人 :
 *  日期  :
 *************************************************************************************/
/* 定义防止递归的包容 */
#ifndef _KEY_H
#define _KEY_H

#ifdef __cplusplus
extern "C"{
#endif
 
/*------------------------按键相关I/O宏定义----------------------------------*/    
#define   KEY1_PORT         GPIOF
#define   KEY1_PIN          GPIO_Pin_6
#define   KEY1_CLK          RCC_AHB1Periph_GPIOF
#define   KEY1_EXTI_LINE    EXTI_Line6
#define   KEY1_EXTI_PORT    EXTI_PortSourceGPIOF
#define   KEY1_EXTI_PIN     EXTI_PinSource6
#define   KEY1_NVIC_IRQ     EXTI9_5_IRQn
    
#define   KEY2_PORT         GPIOF
#define   KEY2_PIN          GPIO_Pin_7
#define   KEY2_CLK          RCC_AHB1Periph_GPIOF
#define   KEY2_EXTI_LINE    EXTI_Line7
#define   KEY2_EXTI_PORT    EXTI_PortSourceGPIOF
#define   KEY2_EXTI_PIN     EXTI_PinSource7
#define   KEY2_NVIC_IRQ     EXTI9_5_IRQn
    
#define   KEY3_PORT         GPIOF
#define   KEY3_PIN          GPIO_Pin_8
#define   KEY3_CLK          RCC_AHB1Periph_GPIOF
#define   KEY3_EXTI_LINE    EXTI_Line8
#define   KEY3_EXTI_PORT    EXTI_PortSourceGPIOF
#define   KEY3_EXTI_PIN     EXTI_PinSource8
#define   KEY3_NVIC_IRQ     EXTI9_5_IRQn

#define   KEY4_PORT         GPIOF
#define   KEY4_PIN          GPIO_Pin_9
#define   KEY4_CLK          RCC_AHB1Periph_GPIOF
#define   KEY4_EXTI_LINE    EXTI_Line9
#define   KEY4_EXTI_PORT    EXTI_PortSourceGPIOF
#define   KEY4_EXTI_PIN     EXTI_PinSource9
#define   KEY4_NVIC_IRQ     EXTI9_5_IRQn

/*----------------------------按键函数声明-------------------------------------*/  
void   KEY1_Init(void);
void   KEY2_Init(void);
void   KEY3_Init(void);
void   KEY4_Init(void);

#ifdef __cplusplus
}
#endif

#endif/*key.h*/

/************************************文件结束******************************************/




