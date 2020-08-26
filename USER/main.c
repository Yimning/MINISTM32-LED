#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "relay.h"
//ALIENTEK Mini STM32开发板范例代码3
//串口实验
//技术论坛:www.openedv.com	

 int main(void)
 {
	u8 t;
	u8 len;	
	u16 static times1=0;  
  u16 static times2=0; 
  u16 static times3=0; 	 
 	SystemInit();//系统时钟等初始化
	delay_init();	     //延时初始化
	LED_Init();	 //LED端口初始化
	NVIC_Configuration();//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);//串口初始化为9600
	RELAY_Init();
	printf("蓝牙控制LED\r\n"); 
	printf("发送1控制LED0\r\n"); 
	printf("发送2控制LED1\r\n"); 
  printf("发送3控制LED0和LED1\r\n"); 
	printf("发送4控制继电器开\r\n");
	printf("发送5控制继电器关\r\n");
	printf("\r\r\r\n");
	 LED0=1;
	 LED1=1;
	while(1)
	{
	  switch(Bluetooth_data)
		{
            case  '1':    //尽量定义使用case0的情况  影响状态  
							    if(times1%2==0) 
									{
										LED0=0;
										 printf("当前灯LED0亮\r\n");
									}else 
									   {LED0=1;printf("当前灯LED0灭\r\n");}
						       times1++;
					    	printf("已发送1次数为%d次\r\n",times1);
             break; 
						
						case  '2':
							    if(times2%2==0) 
									{
										LED1=0;
										 printf("当前灯LED0亮\r\n");
									}else 
									   {LED1=1;printf("当前灯LED0灭\r\n");}
						       times2++;
					    	printf("已发送2次数为%d次\r\n",times2);
							break;
						
					  case  '3': 
							  printf("当前控制LED0和LED1\r\n"); 
							     LED0=!LED0;
						       LED1=!LED1;
					 		break;
					  case  '4': 
							  printf("已收到数据'4',当前控制继电器开\r\n"); 
							    RELAY = 0 ;
						     printf("-----------------------------------\r\n");
					 		break;
						case  '5': 
							  printf("已收到数据'5',当前控制继电器关\r\n"); 
							   RELAY= 1 ;
						     printf("-----------------------------------\r\n"); 
					 		break;
    }
	}	 

 }
 
 					 
// 		switch(BUF_RX_PID)
//  		
// 		{

//  				case 0x02:k=2;	break; //前进标志
// 				
//  			    case 0x01: k=1; break;//后退标志
//  			
//  				case 0x00: k=0;	break;//停止标志
//  						
//  				case 0x03: k=3;	break;//左转标志
// 				
// 				case 0x04: k=4;	break;//右转标志
//  			    
//  				case 0x05: k=5;	break;//原地高速左转标志
// 				
// 				case 0x06: k=6;	break;//原地高速右转标志
//           
//              	case 0x07: k=7;	break;//原地低速右转标志

// 				case 0x08: k=8;	break;//原地低速标志
//  		}

