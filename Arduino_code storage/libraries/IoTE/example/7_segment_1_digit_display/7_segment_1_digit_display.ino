#include <IoTe.h>

// เอาไว้เเสดงผลบน 7-segment credit-temz

void setup() {
  /* เริ่มต้นการประกาศ pin สำหรับ 7 sigment
     Segment_begin(A,B,C,D,E,F,G,DP,
     ACTIVE_PIN_1,
     ACTIVE_PIN_2,
     ACTIVE_PIN_3,
     ACTIVE_PIN_4
     ) 
  */
  Segment_begin(1,2,3,4,5,A0,A1,A2,8,9,10,11);

}

void loop() {
    /* เเสดงผล 7 segment 
       displaysegment( 
        เลขที่จะเเสดงผล,
        จุดทศนิยม,
        เเสดงผล digit
       )
    */
    for(int i = 0; i < 9; i++){
      delay(1000);
      displaysegment(i,1,1);
    } 
}
