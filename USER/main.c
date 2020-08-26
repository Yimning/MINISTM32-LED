#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "relay.h"
//ALIENTEK Mini STM32�����巶������3
//����ʵ��
//������̳:www.openedv.com	

 int main(void)
 {
	u8 t;
	u8 len;	
	u16 static times1=0;  
  u16 static times2=0; 
  u16 static times3=0; 	 
 	SystemInit();//ϵͳʱ�ӵȳ�ʼ��
	delay_init();	     //��ʱ��ʼ��
	LED_Init();	 //LED�˿ڳ�ʼ��
	NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);//���ڳ�ʼ��Ϊ9600
	RELAY_Init();
	printf("��������LED\r\n"); 
	printf("����1����LED0\r\n"); 
	printf("����2����LED1\r\n"); 
  printf("����3����LED0��LED1\r\n"); 
	printf("����4���Ƽ̵�����\r\n");
	printf("����5���Ƽ̵�����\r\n");
	printf("\r\r\r\n");
	 LED0=1;
	 LED1=1;
	while(1)
	{
	  switch(Bluetooth_data)
		{
            case  '1':    //��������ʹ��case0�����  Ӱ��״̬  
							    if(times1%2==0) 
									{
										LED0=0;
										 printf("��ǰ��LED0��\r\n");
									}else 
									   {LED0=1;printf("��ǰ��LED0��\r\n");}
						       times1++;
					    	printf("�ѷ���1����Ϊ%d��\r\n",times1);
             break; 
						
						case  '2':
							    if(times2%2==0) 
									{
										LED1=0;
										 printf("��ǰ��LED0��\r\n");
									}else 
									   {LED1=1;printf("��ǰ��LED0��\r\n");}
						       times2++;
					    	printf("�ѷ���2����Ϊ%d��\r\n",times2);
							break;
						
					  case  '3': 
							  printf("��ǰ����LED0��LED1\r\n"); 
							     LED0=!LED0;
						       LED1=!LED1;
					 		break;
					  case  '4': 
							  printf("���յ�����'4',��ǰ���Ƽ̵�����\r\n"); 
							    RELAY = 0 ;
						     printf("-----------------------------------\r\n");
					 		break;
						case  '5': 
							  printf("���յ�����'5',��ǰ���Ƽ̵�����\r\n"); 
							   RELAY= 1 ;
						     printf("-----------------------------------\r\n"); 
					 		break;
    }
	}	 

 }
 
 					 
// 		switch(BUF_RX_PID)
//  		
// 		{

//  				case 0x02:k=2;	break; //ǰ����־
// 				
//  			    case 0x01: k=1; break;//���˱�־
//  			
//  				case 0x00: k=0;	break;//ֹͣ��־
//  						
//  				case 0x03: k=3;	break;//��ת��־
// 				
// 				case 0x04: k=4;	break;//��ת��־
//  			    
//  				case 0x05: k=5;	break;//ԭ�ظ�����ת��־
// 				
// 				case 0x06: k=6;	break;//ԭ�ظ�����ת��־
//           
//              	case 0x07: k=7;	break;//ԭ�ص�����ת��־

// 				case 0x08: k=8;	break;//ԭ�ص��ٱ�־
//  		}

