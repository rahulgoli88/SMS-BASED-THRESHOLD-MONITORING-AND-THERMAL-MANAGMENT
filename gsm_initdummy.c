#include "types.h"
#include "delay.h"
#include "lcd.h"
#include "uart0.h"
#include<stdlib.h>
#include<string.h>

extern char buff[100],i;
u8 *gsmat[]={"AT\r\n","ATE0\r\n","AT+CMGF=1\r\n",
				"AT+CMGD=1\r\n","AT+CNMI=2,1,0,0,0\r\n","AT+CMGS="};

u8 *gsmresp[]={"OK","ERROR "};
void GSM_init(void)
{	
	u32 j=0;
	Write_CMD_LCD(0x80);
	Write_str_LCD("GSM init....");
	for(j=0;j<5;j++)
	{
		i=0;memset(buff,'\0',100);
		UART_str((char *)gsmat[j]);
		while(i<2);
		delay_ms(500);
		buff[i] = '\0';
		if(strstr(buff,(const char *)gsmresp[0]))
		{		
			Write_CMD_LCD(0xC0);
			Write_str_LCD((char *)gsmresp[0]);
			delay_ms(500);
			Write_CMD_LCD(0xC0);
			Write_str_LCD("  ");
		}
		else
		{
			Write_CMD_LCD(0xC0);
			Write_str_LCD((char *)gsmresp[1]);
			delay_ms(500);
			Write_CMD_LCD(0xC0);
			Write_str_LCD("     ");
		}
	}
}

void send_sms(char *num,char *msg)
{
	Write_CMD_LCD(0x01);
	Write_str_LCD("Sending sms....");
	delay_ms(500);
	i=0;memset(buff,'\0',100);
	delay_ms(500);
	UART_str("AT+CMGS=");
	UART_Tx('"');
	UART_str((char *)num);
	UART_Tx('"');
	UART_str("\r\n");
	delay_ms(500);
	i=0;
	UART_str((char *)msg);
    UART_Tx(0x1A);
	delay_ms(2000);
	while(i<3);
	buff[i] = '\0';
	if(strstr(buff,"OK"))
	{
		Write_CMD_LCD(0x01);
		Write_str_LCD("Message Sent..");
		delay_ms(500);
	}
	else
	{
		Write_CMD_LCD(0x01);
		Write_str_LCD("Message failed..");
		delay_ms(500);
	}
}
void send_sms_info(char *num,char *msg,int k)
{
	Write_CMD_LCD(0x01);
	Write_str_LCD("Sending sms....");
	delay_ms(500);
	i=0;memset(buff,'\0',100);
	delay_ms(500);
	UART_str("AT+CMGS=");
	UART_Tx('"');
	UART_str((char *)num);
	UART_Tx('"');
	UART_str("\r\n");
	delay_ms(500);
	i=0;
	UART_str((char *)msg);
	UART0_Int(k);
	UART_Tx('C');
    UART_Tx(0x1A);
	delay_ms(4000);
	while(i<5);
	buff[i] = '\0';
	if(strstr(buff,"OK"))
	{
		Write_CMD_LCD(0x01);
		Write_str_LCD("Message Send.");
		delay_ms(500);
		
	}
	//i++;
	else
	{
	delay_ms(100);
		Write_CMD_LCD(0x01);
		Write_str_LCD("Message Failed..");
		delay_ms(500);
	}
}
 