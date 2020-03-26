/*************************************************************************************
 * @文件  : key.c
 * @作者  : caochao
 * @日期  : 22-9-2017
 * @摘要  : 这个C文件时实现按键以及中断的初始化
 *
 * 修改人 :
 *  日期  :
 *
 * 修改人 :
 *  日期  :
 *************************************************************************************/
#include "misc.h"
#include "stm32f4xx.h"
#include "key.h"

/************************************************************************************
*   函数名：KEY1_Init(void)
*   功  能：配置按键key1的I/O的功能
*   输  入：
*          无
*   输  出：
*          无
************************************************************************************/
void KEY1_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure;
    EXTI_InitTypeDef   EXTI_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;
    
    /*打开按键的GPIO时钟*/
    RCC_AHB1PeriphClockCmd(KEY1_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*初始化GPIO设置*/
    GPIO_Init(KEY1_PORT,&GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY1_EXTI_PORT,KEY1_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY1_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*初始化中断模式*/
    EXTI_Init(& EXTI_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY1_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;  //子优先级为0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
    /*初始化中断优先级*/
    NVIC_Init(&NVIC_InitStructure);
}

/***********************************************************************************
 *   函数名：KEY2_Init(void)
 *   功  能：配置按键key2的I/O的功能
 *   输  入：
 *          无
 *   输  出：
 *          无
 **********************************************************************************/
void KEY2_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef  EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    /*打开按键的GPIO时钟*/
    RCC_AHB1PeriphClockCmd(KEY2_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*初始化GPIO设置*/
    GPIO_Init(KEY2_PORT,&GPIO_InitStructure);  

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY2_EXTI_PORT,KEY2_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY2_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;    //下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*初始化中断模式*/
    EXTI_Init(&EXTI_InitStructure);   

    NVIC_InitStructure.NVIC_IRQChannel = KEY2_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;   //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;  //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /*初始化中断优先级*/
    NVIC_Init(&NVIC_InitStructure);
}

/***********************************************************************************
 *   函数名：KEY3_Init(void)
 *   功  能：配置按键key3的I/O的功能
 *   输  入：
 *          无
 *   输  出：
 *          无
 **********************************************************************************/
void KEY3_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef   EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    /*打开按键的GPIO时钟*/
    RCC_AHB1PeriphClockCmd(KEY3_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*初始化GPIO设置*/
    GPIO_Init(KEY3_PORT,&GPIO_InitStructure); 
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY3_EXTI_PORT,KEY3_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY3_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*初始化中断模式*/
    EXTI_Init(&EXTI_InitStructure); 
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY3_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;    //子优先级为2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    /*初始化中断优先级*/
    NVIC_Init(&NVIC_InitStructure);
}

/**********************************************************************************
 *   函数名：KEY4_Init(void)
 *   功  能：配置按键key4的I/O的功能
 *   输  入：
 *          无
 *   输  出：
 *          无
 ********************************************************************************/
void KEY4_Init(void)   
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef  EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    RCC_AHB1PeriphClockCmd(KEY4_CLK,ENABLE);
    /*打开按键的GPIO时钟*/
    GPIO_InitStructure.GPIO_Pin = KEY4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*初始化GPIO设置*/
    GPIO_Init(KEY4_PORT,&GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY4_EXTI_PORT,KEY4_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY4_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;     //下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*初始化中断模式*/
    EXTI_Init(&EXTI_InitStructure); 
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY4_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;         //子优先级为3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /*初始化中断优先级*/
    NVIC_Init(&NVIC_InitStructure);
}
/**************************************文件结束*************************************/
