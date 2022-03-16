/**
  ******************************************************************************
  * @file    main.c
  * @author  iotts
  * @version V1.0
  * @date    2022-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "iolog.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	// USART1 配置模式为 115200 8-N-1，中断接收
	USART1_Config();
	
	NVIC_Configuration();

	logi("Hello IOTTS");	
	logi("Hello IOTTS");	
    logw("Hello IOTTS"); 
    loge("Hello IOTTS"); 
    logd("Hello IOTTS"); 
    log4g("Hello IOTTS"); 
	for(;;)
	{
		
	}
}
/*********************************************END OF FILE**********************/
