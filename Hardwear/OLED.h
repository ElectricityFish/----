#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);
void OLED_Clear(void);//清屏
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);//如果数字长度比设置长度短会在前面补零，反之会把前面的数字删掉
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);//显示16进制数
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);//显示二进制数，输入的是16进制数（C语言不支持直接写2进制数）

#endif
