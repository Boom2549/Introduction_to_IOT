#include <IoTe.h>

// เอาไว้เเสดงผลบน 7-segment credit-temz
/*
 mode 1 = wavedrive
 mode 2 = fulldrive
 mode 3 = halfdrive

 true = couter clock wise
 false = clock wise
*/
void setup() {
  /* เริ่มต้นการประกาศ pin สำหรับ 7 sigment
     Segment_begin(BLUE,PINK,YELLOW,ORANGE) ;
  */
  step_motor_begin(8, 9, 10, 11);
}

void loop() {
  // ขับ step motor เเบบที่ 2,step ละ 1.4 degree,หมุนตามเข็ม
  drive(3, 1.4, false);
}
