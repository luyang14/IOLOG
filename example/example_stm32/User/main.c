/**
  ******************************************************************************
  * @file    main.c
  * @author  iotts
  * @version V1.0
  * @date    2022-xx-xx
  * @brief   �����жϽ��ղ���
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "iolog.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	// USART1 ����ģʽΪ 115200 8-N-1���жϽ���
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
