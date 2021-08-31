#include <stdio.h>
#include <stdlib.h>

void add(char *c1, char *c2, char *sum){
     int array[9];
     int kalan = 0;
     int i=0;
     for(i = 7; i >= 0;i--){
             int tempc1,tempc2;
             if(c1[i]=='A'||c1[i]=='B'||c1[i]=='C'||c1[i]=='D'||c1[i]=='E'||c1[i]=='F'){
                 tempc1 = c1[i] - 55;
             }
             else{
                 tempc1 = c1[i] - 48;
             }
             if(c2[i]=='A'||c2[i]=='B'||c2[i]=='C'||c2[i]=='D'||c2[i]=='E'||c2[i]=='F'){
                 tempc2 = c2[i] - 55;
             }
             else{
                 tempc2 = c2[i] - 48;
             }
             array[i] = (tempc1+tempc2+kalan)%16;
             kalan = (tempc1+tempc2)/16;
     }
     for(i=0;i<8;i++){
             if(array[i]==10||array[i]==11||array[i]==12||array[i]==13||array[i]==14||array[i]==15){
                 sum[i]=array[i]+55;
                 //printf("%c-",sum[i]);
             }
             else{
                 sum[i]=array[i]+48;
                 //printf("%c-",sum[i]);
             }
     }
     //printf("\n");
}
void ROR_11(char *c){
     int i=0;
     char array[9];
     for(i=0;i<8;i++){
          array[i]=c[i];
     }
     for(i=7;i>=3;i--){
          c[i-3]=array[i];
     }
     c[5]=array[0];
     c[6]=array[1];
     c[7]=array[2];
     
     int temp[9];
     for(i=0;i<8;i++){
             if(c[i]=='A'||c[i]=='B'||c[i]=='C'||c[i]=='D'||c[i]=='E'||c[i]=='F'){
                 temp[i] = c[i] - 55;
             }
             else{
                 temp[i] = c[i] - 48;
             }
     }
     
     for(i=0;i<7;i++){
             if((temp[i]%2)==1){
                 temp[i]=temp[i]-1;
                 temp[i+1]=temp[i+1]+16;
                 temp[i]=temp[i]/2;
             }
             else{
                 temp[i]=temp[i]/2;
             }
     }
     if((temp[7]%2)==1){
             temp[7]=temp[7]-1;
             temp[0]=temp[0]+8;
             temp[7]=temp[7]/2;
     }
     else{
             temp[7]=temp[7]/2;
     }
     /*for(i=0;i<8;i++){
             printf("%d-",temp[i]);
     }*/
     for(i=0;i<8;i++){
             if(array[i]==10||array[i]==11||array[i]==12||array[i]==13||array[i]==14||array[i]==15){
                 c[i]=temp[i]+55;
                 //printf("%c-",sum[i]);
             }
             else{
                 c[i]=temp[i]+48;
                 //printf("%c-",sum[i]);
             }
     }
}
void xor(char *c1, char *c2, char *cr){
     int temp1[9],temp2[9];
     int i=0;
     for(i=0;i<8;i++){
             if(c1[i]=='A'||c1[i]=='B'||c1[i]=='C'||c1[i]=='D'||c1[i]=='E'||c1[i]=='F'){
                 temp1[i] = c1[i] - 55;
             }
             else{
                 temp1[i] = c1[i] - 48;
             }
     }
     for(i=0;i<8;i++){
             if(c2[i]=='A'||c2[i]=='B'||c2[i]=='C'||c2[i]=='D'||c2[i]=='E'||c2[i]=='F'){
                 temp2[i] = c2[i] - 55;
             }
             else{
                 temp2[i] = c2[i] - 48;
             }
     }
     for(i=0;i<8;i++){
             cr[i] = temp2[i] ^ temp1[i];
             //printf("%d xor %d = %d\n",temp1[i],temp2[i],cr[i]);
     }
     for(i=0;i<8;i++){
             if(cr[i]<10){
                   cr[i] = cr[i] + 48;
             }
             else if(cr[i]==10){
                   cr[i] = 'A';
             }
             else if(cr[i]==11){
                   cr[i] = 'B';
             }
             else if(cr[i]==12){
                   cr[i] = 'C';
             }
             else if(cr[i]==13){
                   cr[i] = 'D';
             }
             else if(cr[i]==14){
                   cr[i] = 'E';
             }
             else if(cr[i]==15){
                   cr[i] = 'F';
             }
     }
}
void Gost_S1(char *c){
         if(c[0]=='0'){
             c[0]='4';
         }
         else if(c[0]=='1'){
             c[0]='A';
         }
         else if(c[0]=='2'){
              c[0]='9';
         }
         else if(c[0]=='3'){
              c[0]='2';
         }
         else if(c[0]=='4'){
              c[0]='D';
         }
         else if(c[0]=='5'){
              c[0]='8';
         }
         else if(c[0]=='6'){
              c[0]='0';
         }
         else if(c[0]=='7'){
              c[0]='E';
         }
         else if(c[0]=='8'){
              c[0]='6';
         }
         else if(c[0]=='9'){
              c[0]='B';
         }
         else if(c[0]=='A'){
              c[0]='1';
         }
         else if(c[0]=='B'){
              c[0]='C';
         }
         else if(c[0]=='C'){
              c[0]='7';
         }
         else if(c[0]=='D'){
              c[0]='F';
         }
         else if(c[0]=='E'){
              c[0]='5';
         }
         else if(c[0]=='F'){
              c[0]='3';
         }
         else{
              printf("Error!");
         }
}
void Gost_S2(char *c){
         if(c[1]=='0'){
             c[1]='E';
         }
         else if(c[1]=='1'){
             c[1]='B';
         }
         else if(c[1]=='2'){
              c[1]='4';
         }
         else if(c[1]=='3'){
              c[1]='C';
         }
         else if(c[1]=='4'){
              c[1]='6';
         }
         else if(c[1]=='5'){
              c[1]='D';
         }
         else if(c[1]=='6'){
              c[1]='F';
         }
         else if(c[1]=='7'){
              c[1]='A';
         }
         else if(c[1]=='8'){
              c[1]='2';
         }
         else if(c[1]=='9'){
              c[1]='3';
         }
         else if(c[1]=='A'){
              c[1]='8';
         }
         else if(c[1]=='B'){
              c[1]='1';
         }
         else if(c[1]=='C'){
              c[1]='0';
         }
         else if(c[1]=='D'){
              c[1]='7';
         }
         else if(c[1]=='E'){
              c[1]='5';
         }
         else if(c[1]=='F'){
              c[1]='9';
         }
         else{
              printf("Error!");
         }
}
void Gost_S3(char *c){
         if(c[2]=='0'){
             c[2]='5';
         }
         else if(c[2]=='1'){
             c[2]='8';
         }
         else if(c[2]=='2'){
              c[2]='1';
         }
         else if(c[2]=='3'){
              c[2]='D';
         }
         else if(c[2]=='4'){
              c[2]='A';
         }
         else if(c[2]=='5'){
              c[2]='3';
         }
         else if(c[2]=='6'){
              c[2]='4';
         }
         else if(c[2]=='7'){
              c[2]='2';
         }
         else if(c[2]=='8'){
              c[2]='E';
         }
         else if(c[2]=='9'){
              c[2]='F';
         }
         else if(c[2]=='A'){
              c[2]='C';
         }
         else if(c[2]=='B'){
              c[2]='7';
         }
         else if(c[2]=='C'){
              c[2]='6';
         }
         else if(c[2]=='D'){
              c[2]='0';
         }
         else if(c[2]=='E'){
              c[2]='9';
         }
         else if(c[2]=='F'){
              c[2]='B';
         }
         else{
              printf("Error!");
         }
}
void Gost_S4(char *c){
         if(c[3]=='0'){
             c[3]='7';
         }
         else if(c[3]=='1'){
             c[3]='D';
         }
         else if(c[3]=='2'){
              c[3]='A';
         }
         else if(c[3]=='3'){
              c[3]='1';
         }
         else if(c[3]=='4'){
              c[3]='0';
         }
         else if(c[3]=='5'){
              c[3]='8';
         }
         else if(c[3]=='6'){
              c[3]='9';
         }
         else if(c[3]=='7'){
              c[3]='F';
         }
         else if(c[3]=='8'){
              c[3]='E';
         }
         else if(c[3]=='9'){
              c[3]='4';
         }
         else if(c[3]=='A'){
              c[3]='6';
         }
         else if(c[3]=='B'){
              c[3]='C';
         }
         else if(c[3]=='C'){
              c[3]='B';
         }
         else if(c[3]=='D'){
              c[3]='2';
         }
         else if(c[3]=='E'){
              c[3]='5';
         }
         else if(c[3]=='F'){
              c[3]='3';
         }
         else{
              printf("Error!");
         }
}
void Gost_S5(char *c){
         if(c[4]=='0'){
             c[4]='6';
         }
         else if(c[4]=='1'){
             c[4]='C';
         }
         else if(c[4]=='2'){
              c[4]='7';
         }
         else if(c[4]=='3'){
              c[4]='1';
         }
         else if(c[4]=='4'){
              c[4]='5';
         }
         else if(c[4]=='5'){
              c[4]='F';
         }
         else if(c[4]=='6'){
              c[4]='D';
         }
         else if(c[4]=='7'){
              c[4]='8';
         }
         else if(c[4]=='8'){
              c[4]='4';
         }
         else if(c[4]=='9'){
              c[4]='A';
         }
         else if(c[4]=='A'){
              c[4]='9';
         }
         else if(c[4]=='B'){
              c[4]='E';
         }
         else if(c[4]=='C'){
              c[4]='0';
         }
         else if(c[4]=='D'){
              c[4]='3';
         }
         else if(c[4]=='E'){
              c[4]='B';
         }
         else if(c[4]=='F'){
              c[4]='2';
         }
         else{
              printf("Error!");
         }
}
void Gost_S6(char *c){
         if(c[5]=='0'){
             c[5]='4';
         }
         else if(c[5]=='1'){
             c[5]='B';
         }
         else if(c[5]=='2'){
              c[5]='A';
         }
         else if(c[5]=='3'){
              c[5]='0';
         }
         else if(c[5]=='4'){
              c[5]='7';
         }
         else if(c[5]=='5'){
              c[5]='2';
         }
         else if(c[5]=='6'){
              c[5]='1';
         }
         else if(c[5]=='7'){
              c[5]='D';
         }
         else if(c[5]=='8'){
              c[5]='3';
         }
         else if(c[5]=='9'){
              c[5]='6';
         }
         else if(c[5]=='A'){
              c[5]='8';
         }
         else if(c[5]=='B'){
              c[5]='5';
         }
         else if(c[5]=='C'){
              c[5]='9';
         }
         else if(c[5]=='D'){
              c[5]='C';
         }
         else if(c[5]=='E'){
              c[5]='F';
         }
         else if(c[5]=='F'){
              c[5]='E';
         }
         else{
              printf("Error!");
         }
}
void Gost_S7(char *c){
         if(c[6]=='0'){
             c[6]='D';
         }
         else if(c[6]=='1'){
             c[6]='B';
         }
         else if(c[6]=='2'){
              c[6]='4';
         }
         else if(c[6]=='3'){
              c[6]='1';
         }
         else if(c[6]=='4'){
              c[6]='3';
         }
         else if(c[6]=='5'){
              c[6]='F';
         }
         else if(c[6]=='6'){
              c[6]='5';
         }
         else if(c[6]=='7'){
              c[6]='9';
         }
         else if(c[6]=='8'){
              c[6]='0';
         }
         else if(c[6]=='9'){
              c[6]='A';
         }
         else if(c[6]=='A'){
              c[6]='E';
         }
         else if(c[6]=='B'){
              c[6]='7';
         }
         else if(c[6]=='C'){
              c[6]='6';
         }
         else if(c[6]=='D'){
              c[6]='8';
         }
         else if(c[6]=='E'){
              c[6]='2';
         }
         else if(c[6]=='F'){
              c[6]='C';
         }
         else{
              printf("Error!");
         }
}
void Gost_S8(char *c){
         if(c[7]=='0'){
             c[7]='1';
         }
         else if(c[7]=='1'){
             c[7]='F';
         }
         else if(c[7]=='2'){
              c[7]='D';
         }
         else if(c[7]=='3'){
              c[7]='0';
         }
         else if(c[7]=='4'){
              c[7]='5';
         }
         else if(c[7]=='5'){
              c[7]='7';
         }
         else if(c[7]=='6'){
              c[7]='A';
         }
         else if(c[7]=='7'){
              c[7]='4';
         }
         else if(c[7]=='8'){
              c[7]='9';
         }
         else if(c[7]=='9'){
              c[7]='2';
         }
         else if(c[7]=='A'){
              c[7]='3';
         }
         else if(c[7]=='B'){
              c[7]='E';
         }
         else if(c[7]=='C'){
              c[7]='6';
         }
         else if(c[7]=='D'){
              c[7]='B';
         }
         else if(c[7]=='E'){
              c[7]='8';
         }
         else if(c[7]=='F'){
              c[7]='C';
         }
         else{
              printf("Error!");
         }
}
void rhex(char *c){
     char tempt[9];
     char tempc[9];
     int i=0;
     for(i=0;i<8;i++){
           tempt[i]=c[i];
           tempc[i]=c[i];
     }
     for(i=0;i<16;i++){
           if(i%2==1){
                 int cift = 15;
                 tempt[i/2] = tempt[i/2]&cift;
                 if(tempt[i/2]<10){
                   c[i] = tempt[i/2] + 48;
                 }
                 else if(tempt[i/2]==10){
                       c[i] = 'A';
                 }
                 else if(tempt[i/2]==11){
                       c[i] = 'B';
                 }
                 else if(tempt[i/2]==12){
                       c[i] = 'C';
                 }
                 else if(tempt[i/2]==13){
                       c[i] = 'D';
                 }
                 else if(tempt[i/2]==14){
                       c[i] = 'E';
                 }
                 else if(tempt[i/2]==15){
                       c[i] = 'F';
                 } 
           }
           else{
                 int tek = 240;
                 int cift = 15;
                 tempc[i/2] = tempc[i/2]&tek;
                 tempc[i/2] = tempc[i/2]>>4; 
                 tempc[i/2] = tempc[i/2]&cift;
                 if(tempc[i/2]<10){
                   c[i] = tempc[i/2] + 48;
                 }
                 else if(tempc[i/2]==10){
                       c[i] = 'A';
                 }
                 else if(tempc[i/2]==11){
                       c[i] = 'B';
                 }
                 else if(tempc[i/2]==12){
                       c[i] = 'C';
                 }
                 else if(tempc[i/2]==13){
                       c[i] = 'D';
                 }
                 else if(tempc[i/2]==14){
                       c[i] = 'E';
                 }
                 else if(tempc[i/2]==15){
                       c[i] = 'F';
                 } 
           }
     }
}

void nrhex(char *c){
     char temp[17];
     int i=0;
     for(i=0;i<16;i++){
           if(c[i]=='A'||c[i]=='B'||c[i]=='C'||c[i]=='D'||c[i]=='E'||c[i]=='F'){
                 temp[i] = c[i] - 55;
           }
           else{
                 temp[i] = c[i] - 48;
           }
     }
     for(i=0;i<16;i=i+2){
           int tek = 120;
           int cift = 15;
           
           temp[i] = temp[i]&cift;
           temp[i] = temp[i]<<4;

           temp[i+1] = temp[i+1]&cift;
           
           unsigned int result = temp[i] | temp[i+1];
           
           c[i/2] = result;
           /*printf("%d ",temp[i]);    
           printf("%d\n",temp[i+1]);    
           printf("%d ",c[i/2]);   
           system("pause");*/
     }
}

int main(int argc, char *argv[])
{
    FILE *input;
    char get_char;
    input = fopen("image.bmp", "rb");
    int i = 0;
    int confkey=0; 
    int const cikis = 4;
    char temp[1000000];
    char templast[1000000];
    char const KEY[8][8]={"00100000","00000000","00000000","00000F00","00000000","00000000","00000000","00000000"};
    int arrayC1=0;
    int arrayC2=0;
    while(1)
    {
           int conf = i%8;
           char PLAINTEXT[17];
           if((get_char=fgetc(input))== EOF){
                 //printf("%d\n",get_char);
                 templast[i]=-1;
                 if(i>3){
                        if(templast[i]==-1&&templast[i-1]==-1&&templast[i-2]==-1&&templast[i-3]==-1&&templast[i-4]==-1){
                            break;
                        }
                 }
                 PLAINTEXT[conf]=-1;
           }
           else{
                 PLAINTEXT[conf]=get_char;
                 templast[i]=get_char;
           }
           i++;
           //printf("%d\n",get_char);
           
           if(conf==7){
              rhex(PLAINTEXT);
              char left[9];
              char right[9];
              //char const KEY_1[8]="00100000";
              if(confkey==8&&confkey>5){
                      confkey=0;
              }
              char KEY_1[9];
              int e=0;
              for(e=0;e<8;e++){
                      KEY_1[e]=KEY[confkey][e];
              }
              confkey++;
              int j=0;
              for(j=0;j<16;j++){
                      if(j<8){
                           left[j]=PLAINTEXT[j];
                      }
                      else if(j>7){
                           right[j-8]=PLAINTEXT[j];
                      }
              }
              for(j=0;j<32;j++){
                  char sum[9];
                  
                  add(right,KEY_1,sum);
                  
                  
                  Gost_S1(sum);
                  Gost_S2(sum);
                  Gost_S3(sum);
                  Gost_S4(sum);
                  Gost_S5(sum);
                  Gost_S6(sum);
                  Gost_S7(sum);
                  Gost_S8(sum);
                  
                  ROR_11(sum);
                  
                  char newleft[9];
                  xor(sum,left,newleft);
                  	
                  int k=0;
                 
                  char tempC[9];
                  for(k=0;k<8;k++){
                         tempC[k]= right[k];
                         right[k] = newleft[k];
                         left[k]=tempC[k];
                  }
                  if(j==31){
                          /*printf("encryted          : ");
                          for(j=0;j<8;j++){
                               printf("%c",right[j]);
                          }
                          printf(" ");
                          for(j=0;j<8;j++){
                               printf("%c",left[j]);
                          }*/
                          int bolum = i/8-1;
                          for(j=0;j<16;j++){
                               if(j<8){
                                       temp[bolum*16+j]=right[j];
                                       arrayC1++;
                               }
                               else{
                                       temp[bolum*16+j]=left[j-8];
                                       arrayC1++;
                               }
                          }
                          //printf("\n");
                          break;
                  }
              }
           }
           
    }
    fclose(input);
    
    FILE *output;
    char set_char;
    output = fopen("image_out.bmp", "wb");
    int j=0;
    char gecici[17];
    for(j=1;j<=arrayC1;j++){
           gecici[(j-1)%16]=temp[j-1];
           if(j%16==0&&j>10){
                nrhex(gecici);
                int i=0;
                int kalan = j/16-1;
                for(i=0;i<8;i++){
                      temp[8*kalan+i]=gecici[i];
                      arrayC2++;
                }
           }
    }
    for(j=arrayC2;j<i;j++){
           temp[j]=templast[j];
           arrayC2++;
    }
    for(j=1;j<=arrayC2-cikis;j++){
           fputc(temp[j-1],output);
    }
    fclose(output);
    printf("\ni = %d , C1 = %d , C2 = %d\n",i,arrayC1,arrayC2); 
    
    system("pause");
    return 0;
}

