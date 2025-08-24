#include<cstdio>
#include<cstring>
/*void display(int DATA2[100]){
    for(int i=0;i<100;i++){
        printf("%d ",DATA2[i]);
    }
}*/
int Calculation(int DATA1_value[100],int DATA2_value[100]){
    int DATA1=0;
    int DATA2=0;
    int answer=0;
    for(int i=0;i<100;i++){ //將DATA1數值陣列轉換為數值
        if(DATA1_value[i]==0){break;}
        if(DATA1_value[i]<DATA1_value[i+1]){
            DATA1 = DATA1+(DATA1_value[i+1]-DATA1_value[i]);
            i++;
        }else{
            DATA1+=DATA1_value[i];
        }
    }
    for(int i=0;i<100;i++){//將DATA2數值陣列轉換為數值
        if(DATA2_value[i]==0){break;}
        if(DATA2_value[i]<DATA2_value[i+1]){
            DATA2 = DATA2+(DATA2_value[i+1]-DATA2_value[i]);
            i++;
        }else{
            DATA2+=DATA2_value[i];
        }
    }
    //printf("%d %d\n",DATA1,DATA2);
    if(DATA1>DATA2){
        return (DATA1-DATA2);
    }else if(DATA2>DATA1){
        return (DATA2-DATA1);
    }else if(DATA1 == DATA2){
        return 0;
    }
    return 0;
}
int main(){
   char Roman_alphabet[7] = {'M','D','C','L','X','V','I'};
   int Roman_alphabet_value[7]={1000,500,100,50,10,5,1};
   char DATA1[100];
   char DATA2[100];
   int DATA1_value[100];
   int DATA2_value[100];
   for(int i=0;i<100;i++){ //初始化陣列
       DATA1[i] = ' ';
       DATA1_value[i] = 0;
       DATA2[i]= ' ';
       DATA2_value[i]=0;
   }
   while(scanf("%s",DATA1)!=EOF){
       if(DATA1[0]=='#'){break;}
       if(scanf("%s",DATA2)!=EOF){
       if(DATA1[0]=='#'||DATA2[0]=='#'){break;}//若測資為#則結束程式
       for(int i=0;i<strlen(DATA1);i++){//比較輸入資料的字母並將輸入的第一筆資料轉換為數字
           for(int j=0;j<7;j++){
               if(DATA1[i]==Roman_alphabet[j]){
                   DATA1_value[i] = Roman_alphabet_value[j];
               }
           }
       }
       for(int i=0;i<strlen(DATA2);i++){//比較輸入資料的字母並將輸入的第二筆資料轉換為數字
           for(int j=0;j<7;j++){
               if(DATA2[i]==Roman_alphabet[j]){
                   DATA2_value[i] = Roman_alphabet_value[j];
               }
           }
       }
       int DATA3 = Calculation(DATA1_value,DATA2_value);//將兩者相差的絕對值計算並儲存
       if(DATA3==0){
           printf("ZERO\n");
           for(int i=0;i<100;i++){
               DATA1[i] = 0;
               DATA2[i] = 0;
               DATA1_value[i] = 0;
               DATA2_value[i] = 0;
           }
           continue;
       }
       char ANSWER[100];
       for(int i=0;i<100;i++){
           ANSWER[i] = ' ';
       }
       int Thousands = 0;
       int Hundreds = 0;
       int Tendigits = 0;
       int Digits = 0;
       if(DATA3>999){ //取千位數
           Thousands = (DATA3/1000);
       }
       if(DATA3>99){//取百位數
           Hundreds = (DATA3%1000)/100;
       }
       if(DATA3>9){//取十位數
           Tendigits = ((DATA3%1000)%100)/10;
       }
       if(DATA3>0){//取個位數
           Digits = (((DATA3%1000)%100)%10);
       }
       //printf("%d %d %d %d\n",Thousands,Hundreds,Tendigits,Digits);
       /*將數字轉為羅馬數字*/
       for(int i=0;i<Thousands;i++){printf("M");}//顯示千位羅馬數字
       //顯示百位羅馬數字
       if(Hundreds<4&&Hundreds!=0){
           for(int i=0;i<Hundreds;i++){
               printf("C");
           }
       }else if(Hundreds>6&&Hundreds<9){
           printf("D");
           for(int i=0;i<(Hundreds-5);i++){
               printf("C");
           }
       }else if(Hundreds==4){printf("CD");
       }else if(Hundreds==6){printf("DC");
       }else if(Hundreds==5){printf("D");
       }else if(Hundreds==9){printf("CM");}

       if(Tendigits>6&&Tendigits<9){//顯示十位數
          printf("L");
          for(int i=0;i<(Tendigits-5);i++){
              printf("X");
          }
       }else if(Tendigits<4&&Tendigits!=0){
          for(int i=0;i<Tendigits;i++){
              printf("X");
          }
       }else if(Tendigits==4){
           printf("XL");
       }else if(Tendigits==5){
           printf("L");
       }else if(Tendigits==6){
           printf("LX");
       }else if(Tendigits==9){
           printf("XC");
       }
       if(Digits<4&&Digits!=0){
          for(int i=0;i<Digits;i++){
              printf("I");
          }
       }else if(Digits>6&&Digits<9){
          printf("V");
          for(int i=0;i<Digits-5;i++){
              printf("I");
          }
       }else if(Digits==4){
           printf("IV");
       }else if(Digits==5){
           printf("V");
       }else if(Digits==6){
           printf("VI");
       }else if(Digits==9){
           printf("IX");
       }
       /*if(Thousands==Hundreds&&Hundreds==Tendigits&&Tendigits==Digits&&Digits==0){
           char ZERO[4] = {'Z','E','R','O'};
           printf("%s",ZERO);
       }*/
       printf("\n");
       /*歸零*/
       for(int i=0;i<100;i++){
           DATA1[i] = ' ';
           DATA1_value[i] = 0;
           DATA2[i] = ' ';
           DATA2_value[i] = 0;
       }
     }
   }
   return 0;
}
