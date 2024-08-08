#include "util.h"

// 演習用のユーティリティ


// 初期処理用
void init_f(const char *str) {
  // フォントの設定と0行目の表示
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(str, 0, 0);
  
  tslp_tsk(50*1000U);
  printf("%s\n",str);
  fp = fopen("log.txt","w");
  printf("file opened \n");
  
}

/**
 * 行単位で引数の文字列を表示
 * @param str 表示する文字列
 * @param line 20ドットごとの行番号（1から5）
 */
void msg_f(const char *str, int32_t line) {
  const int8_t line_height = 20;
  ev3_lcd_fill_rect(0, line * line_height, EV3_LCD_WIDTH, line_height, EV3_LCD_WHITE);
  ev3_lcd_draw_string(str, 0, line * line_height);
}


void msg_log(const char *str)
{
  //syslog(LOG_NOTICE,str);
  printf(str);
  if(fp!=nullptr) fprintf(fp,str);
}
void msg_num(char c,double x,double y,double z,  double w,double p)
{
  msg_logbuf[log_idx][0]=c;  
  msg_logbuf[log_idx][1]=x;
  msg_logbuf[log_idx][2]=y;
  msg_logbuf[log_idx][3]=z;
  msg_logbuf[log_idx][4]=w;
  msg_logbuf[log_idx][5]=p;
  log_idx++;
  if(log_idx>=log_max) log_idx=0;

}
void msg_out()
{
  printf("msg_out\n");
  //printf("log_out %d\n",log_idx);
  for(int i=0;i<log_idx;i++) {
    //printf("%f,%f,%f %f\n",msg_logbuf[i][0],msg_logbuf[i][1],msg_logbuf[i][2],msg_logbuf[i][3]);
    fprintf(fp,"%c,%f  ,%f,%f ,%f,%f\n",(char)msg_logbuf[i][0],msg_logbuf[i][1],msg_logbuf[i][2],msg_logbuf[i][3],msg_logbuf[i][4],msg_logbuf[i][5]);
  }
  fclose(fp);
  log_idx=0;  
}