#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
int umur;
float jangkung;
scanf("%d", &umur);
scanf("%f", &jangkung);

if(umur < 18){
printf("Anjeun masih leutik\n");
}else if(umur == 18){
printf("Anjeun geus dewasa\n");
}else{
printf("Anjeun geus kolot\n");
}

if(jangkung >= 1.75){
printf("Anjeun jangkung\n");
}else{
printf("Anjeun pendek\n");
}




return 0;
}