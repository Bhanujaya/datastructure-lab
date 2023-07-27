//ให้นิสิตเขียนโปรแกรมภาษา C ทำการรับข้อมูลชื่อนิสิตและรับคะแนนเป็นเลขจำนวนเต็ม เป็นจำนวน 5 คน  ทำการหาค่าเฉลี่ย พิมพ์ค่าเฉลี่ยโดยมีทศนิยม 2 ตำแหน่ง แล้วพิมพ์ชื่อและคะแนนของคนที่มีคะแนนมากกว่าค่าเฉลี่ยออกมา
//ให้ส่งโปรแกรม และ หน้าจอการประมวลผลโปรแกรม

int main() {
    int i ;
    char students[6];
    int score[6];

    for (i = 0  ;  i < 5 ; i ++  ) {

    printf( "Enter student name: ");
    scanf("%s", students[i]);
    printf("Enter student score: ");
    scanf("%d", score[i]);

    totalScore += score[i];

   
    }
    average = totalScore/5.0;
    printf("");
    for (i = 0  ;  i < 5 ; i ++  ) {

    if (scores[i] > average) {
        printf(" %s : %d " ,students[i] , score[i]);
    }

   
    }



}
