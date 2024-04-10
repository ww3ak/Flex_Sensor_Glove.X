/* 
 * File:   lcd.h
 * Author: sabri
 *
 * Created on April 10, 2024, 10:55 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

void delay_ms(unsigned int ms);
void lcd_cmd(char Package);
void lcd_init();
void lcd_setCursor(char x, char y);
void lcd_printStr(const char s[]);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

