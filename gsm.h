#ifndef _GSM_H_
#define _GSM_H_
void GSM_init(void);
void send_sms(char *num,char *msg);
void send_sms_info(char *num,char *msg,int);
void read_sms(void);
#endif
