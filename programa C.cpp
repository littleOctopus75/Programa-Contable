Elaborado por: German Luis Cruz Martinez
Eder Euclides Dionisio Diaz
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
void gotoxy(int x,int y){
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos);
}
struct cuenta{
int clave;
char clavecuen[10];
char nomcuenta[50];
float cargo;
float abono;
};
struct cuenta cunetas;
void cuenta();
void crear_cuenta(int y,char cuenta[]);
void balance_comprobacion();
void balanze_general();
void estado_resultados();
void tablaesquema_mayor();
void esquema_mayor1();
void esquema_mayor2();
void esquema_mayor3();
void esquema_mayor4();
void esquema_mayor5();
void cierre_ejercicio();
void cierre_esquema();
int opc,opc1,i,j,k,opc2;
int auxc[60][10],auxa[60][10];
char nomcuenta[60][20];
int monto,cont,cont1,suma,suma1,total1,total2,total,cuenta1,total3,total4;
int movimientos[2][60][15],aux[60];
char activosc[12][30]={{"Caja"},{"Bancos"},{"Inverciones Temporales"},
{"Mercancias"},{"Clientes"},{"documento por cobrar"},
{"Deudores diversos"},{"Anticipo proveedores"},{"IVA
acreditable"},{"IVA pendiente de acreditar"}};
char activosf[8][30]={{"Terrenos"},{"Edificios"},{"Movivliario y Eq"},
{"Equipo de computo"},{"Equipo de reparto"},
{"Deposito en grantia"},{"Inverciones permanentes"}};
char activosd[11][40]={{"Gastos de invercion y desarollo"},{"Gastos en etapas preoperativas"},
{"Gastos de mercadotecnia"},{"Gastos de
organizacion"},{"Gastos de instalacion"},
{"Papeleria y utiles"},{"Propaganda y
publicidad"},{"Primas de seguros"},
{"Rentas pagadas por anticipado"},{"Intereses
pagados por anticipado"}};
char pasivoc[9][30]={{"Proveedores"},{"Documento por pagar"},{"Acredores diversos"},
{"Anticipo a clientes"},{"Gastos pendientes de
pago"},
{"Impuestos pendientes de pago"},{"IVA pendiente
de pago"},{"Retencion a terceros"}};
char pasivof[4][50]={{"Ipotecas por pagar a acredores"},{"Documentos por pagar a largo plazo"},
{"Cuentas por pagar a largo plazo"}};
char pasivod[3][50]={{"Rentas cobradas por anticipado"},{"Intereses cobradas por anticipados"}};
char otros[15][50]={{"Ventas"},{"Devolucion y rebajas s/ventas"},{"Compras"},{"Gastos
compra"},{"Devoluciones y rebajas s/compras"},{"Inventario inicial"},
{"Inventario final"},{"Gastos generales"},{"Otros
productos"},{"Otros gastos"},{"Productos Financieros"},{"Gastos financieros "}};
char capital[2][25]={{"Capital social"}};
int main(){
int opc;
gotoxy(30,12);printf("Bienvenido al sistema contable ");
for(i=0;i<3;i++){
gotoxy(61+i,12);printf(".");
sleep(1);
}
for(i=0;i<2;i++){
for(j=0;j<50;j++){
for(k=0;k<15;k++){
movimientos[i][j][k]=0;
}
aux[j]=0;
}
}
do{
system("cls");
for(i=0;i<90;i++){
gotoxy(6+i,3);printf("_");
gotoxy(6+i,27);printf("_");
}
for(i=0;i<24;i++){
gotoxy(6,4+i);printf("%c",179);
gotoxy(96,4+i);printf("%c",179);
}
gotoxy(20,8);printf("1.-Crear");
gotoxy(20,10);printf("2.-Esquemas de mayor");
gotoxy(20,12);printf("3.-Mostrar balanza de Comprobacion");
gotoxy(20,14);printf("4.-Mostrar balance general");
gotoxy(20,16);printf("5.-Mostrar Estado de resultados");
gotoxy(20,18);printf("6.-Cierre del ejercicio");
gotoxy(20,20);printf("7.-Cierre del ejercicio - Esquema mayor");
gotoxy(20,22);printf("8.-Salir");
gotoxy(20,24);printf("Elija una opcion : ");
scanf("%d",&opc);
system("cls");
switch(opc){
case 1:
cuenta();
break;
case 2:
gotoxy(45,2);printf("Esquemas de mayor");
tablaesquema_mayor();
esquema_mayor1();
gotoxy(45,36);printf("Precione una tecla para continuar");
getch();
tablaesquema_mayor();
esquema_mayor2();
gotoxy(45,36);printf("Precione una tecla para continuar");
getch();
tablaesquema_mayor();
esquema_mayor3();
gotoxy(45,36);printf("Precione una tecla para continuar");
getch();
tablaesquema_mayor();
esquema_mayor4();
gotoxy(45,36);printf("Precione una tecla para continuar");
getch();
tablaesquema_mayor();
esquema_mayor5();
gotoxy(45,36);printf("Precione una tecla para continuar");
getch();
break;
case 3:
balance_comprobacion();
getch();
break;
case 4:
gotoxy(45,2);printf("La cosecha S.A de C.V de R.V.");
balanze_general();
gotoxy(45,37);printf("Eder Euclides, German luis");
getch();
break;
case 5:
estado_resultados();
getch();
break;
case 6:
cierre_ejercicio();
getch();
break;
case 7:
cierre_esquema();
getch();
break;
}
}while(opc!=8);
return 0;
}
void cuenta(){
int y=0;
int part=0,part1=0;
char cuenta[25],a=0,b=0,ban1,band;
for(i=0;i<90;i++){
gotoxy(10+i,5);printf("_");
gotoxy(10+i,7);printf("_");
}
for(i=0;i<20;i++){
gotoxy(10,6+i);printf("|");
gotoxy(22,6+i);printf("|");
gotoxy(68,6+i);printf("|");
gotoxy(83,6+i);printf("|");
gotoxy(100,6+i);printf("|");
}
gotoxy(11,6);printf("Codigo");
gotoxy(23,6);printf("Concepto");
gotoxy(70,6);printf("Cargo");
gotoxy(85,6);printf("Abono");
gotoxy(15,26);printf("Desea ingresar una cuenta Si=1, NO=0, ver codigos de cuenta=2 : ");
scanf("%d",&opc);
if(opc==2){
gotoxy(15,27);printf("activo- circulante=1, fijo=2, diferido=3");
gotoxy(15,28);printf("Pasivo- circulante=4, fijo=5, diferido=6");
gotoxy(15,29);printf("Estado de resultados=7, Capital social=8");
gotoxy(15,30);printf("Ingresa que cuenta desea : ");
scanf("%d",&cuenta1);
if(cuenta1==1){
for(i=0;i<10;i++){
gotoxy(103,7+i);printf("100-10-0%d _ ",i+1);
if(i==9){
gotoxy(103,7+i-15);printf("100-30-%d _ ",i+1);
}
gotoxy(115,7+i);puts(activosc[i]);
}
}
if(cuenta1==2){
for(i=10;i<17;i++){
gotoxy(103,7+i-8);printf("100-20-0%d _ ",i-7);
gotoxy(115,7+i-8);puts(activosf[i-8]);
}
}
if(cuenta1==3){
for(i=17;i<27;i++){
gotoxy(103,7+i-15);printf("100-30-0%d _ ",i-16);
if(i==26){
gotoxy(103,7+i-15);printf("100-30-%d _ ",i-16);
}
gotoxy(115,7+i-15);puts(activosd[i-17]);
}
}
if(cuenta1==4){
for(i=27;i<35;i++){
gotoxy(103,7+i-25);printf("200-10-0%d _ ",i-26);
gotoxy(115,7+i-25);puts(pasivoc[i-27]);
}
}
if(cuenta1==5){
for(i=35;i<38;i++){
gotoxy(103,7+i-31);printf("200-20-0%d _ ",i-34);
gotoxy(115,7+i-31);puts(pasivof[i-35]);
}
}
if(cuenta1==6){
for(i=38;i<40;i++){
gotoxy(103,7+i-34);printf("200-30-0%d _ ",i-37);
gotoxy(115,7+i-34);puts(pasivod[i-38]);
}
}
if(cuenta1==7){
for(i=40;i<52;i++){
gotoxy(103,7+i-31);printf("300-20-0%d _ ",i-39);
gotoxy(115,7+i-31);puts(pasivof[i-40]);
}
}
if(cuenta1==8){
for(i=52;i<53;i++){
gotoxy(103,7+i-31);printf("400-20-0%d _ ",i-51);
gotoxy(115,7+i-31);puts(pasivof[i-52]);
}
}
gotoxy(15,26);printf(" ");
gotoxy(15,27);printf(" ");
gotoxy(15,28);printf(" ");
gotoxy(15,29);printf(" ");
gotoxy(15,30);printf(" ");
gotoxy(15,26);printf("Desea ingresar una cuenta Si=1, NO=0 : ");
scanf("%d",&opc);
}
do{
band=0;
ban1=0;
if(opc==1){
gotoxy(12,8+y);gets(cuenta);
crear_cuenta(y,cuenta);
gotoxy(15,27);printf("ELija un movimiento a realizar Cargar=1, Abonoar=0 :
");
scanf("%d",&opc1);
if(cont<53){
cont1=0;
if(opc1==1){
cont1=0;
while(movimientos[0][cont][cont1]!=0){
cont1++;
}
gotoxy(72,8+y);scanf("%d",&movimientos[0][cont][cont1]);
monto=movimientos[0][cont][cont1];
part=part+movimientos[0][cont][cont1];
band=1;
}
if(opc1==0){
cont1=0;
while(movimientos[1][cont][cont1]!=0){
cont1++;
}
gotoxy(87,8+y);scanf("%d",&movimientos[1][cont][cont1]);
monto=movimientos[1][cont][cont1];
part1+=movimientos[1][cont][cont1];
ban1=1;
}
}
}
if(band==1){
auxc[a][0]=cont;
auxc[a][1]=cont1;
auxc[a][2]=monto;
}else{
auxc[a][0]=1000;
auxc[a][1]=1000;
auxc[a][2]=0;
}
if(ban1==1){
auxa[b][0]=cont;
auxa[b][1]=cont1;
auxa[b][2]=monto;
}else{
auxa[b][0]=1000;
auxa[b][1]=1000;
auxa[b][2]=0;
}
for(i=0;i<17;i++){
gotoxy(103,7+i);printf(" ");
}
gotoxy(15,27);printf(" ");
gotoxy(15,26);printf(" ");
gotoxy(15,26);printf("Desea ingresar otra cuenta Si=1, NO=0, ver codigos de
cuenta=2 : ");
scanf("%d",&opc2);
opc=opc2;
if(opc==2){
gotoxy(15,27);printf("activo- circulante=1, fijo=2, diferido=3");
gotoxy(15,28);printf("Pasivo- circulante=4, fijo=5, diferido=6");
gotoxy(15,29);printf("Estado de resultados=7, Capital social=8");
gotoxy(15,30);printf("Ingresa que cuenta desea : ");
scanf("%d",&cuenta1);
if(cuenta1==1){
for(i=0;i<10;i++){
gotoxy(103,7+i);printf("100-10-0%d _ ",i+1);
if(i==9){
gotoxy(103,7+i-15);printf("100-30-%d _ ",i+1);
}
gotoxy(115,7+i);puts(activosc[i]);
}
}
if(cuenta1==2){
for(i=10;i<17;i++){
gotoxy(103,7+i-8);printf("100-20-0%d _ ",i-7);
gotoxy(115,7+i-8);puts(activosf[i-8]);
}
}
if(cuenta1==3){
for(i=17;i<27;i++){
gotoxy(103,7+i-15);printf("100-30-0%d _ ",i-16);
if(i==26){
gotoxy(103,7+i-15);printf("100-30-%d _ ",i-16);
}
gotoxy(115,7+i-15);puts(activosd[i-17]);
}
}
if(cuenta1==4){
for(i=27;i<35;i++){
gotoxy(103,7+i-25);printf("200-10-0%d _ ",i-26);
gotoxy(115,7+i-25);puts(pasivoc[i-27]);
}
}
if(cuenta1==5){
for(i=35;i<38;i++){
gotoxy(103,7+i-31);printf("200-20-0%d _ ",i-34);
gotoxy(115,7+i-31);puts(pasivof[i-35]);
}
}
if(cuenta1==6){
for(i=38;i<40;i++){
gotoxy(103,7+i-34);printf("200-30-0%d _ ",i-37);
gotoxy(115,7+i-34);puts(pasivod[i-38]);
}
}
if(cuenta1==7){
for(i=40;i<51;i++){
gotoxy(103,7+i-31);printf("300-20-0%d _ ",i-39);
gotoxy(115,7+i-31);puts(pasivof[i-40]);
}
}
if(cuenta1==8){
for(i=52;i<53;i++){
gotoxy(103,7+i-31);printf("400-20-0%d _ ",i-51);
gotoxy(115,7+i-31);puts(pasivof[i-52]);
}
}
gotoxy(15,26);printf(" ");
gotoxy(15,27);printf(" ");
gotoxy(15,28);printf(" ");
gotoxy(15,29);printf(" ");
gotoxy(15,30);printf(" ");
gotoxy(15,26);printf("Desea ingresar otra cuenta Si=1, NO=0 : ");
scanf("%d",&opc2);
}
if(opc2==0){
if(part1!=part){
while(part!=part1&&opc2!=2){
gotoxy(15,27);printf("
");
gotoxy(15,26);printf("
");
gotoxy(15,28);printf("
");
gotoxy(15,29);printf("
");
gotoxy(15,26);printf("No puede continuar, no existe
partida doble ");
gotoxy(15,27);printf("Movimiento a modificar Cargo=1,
Abono=0, ingresar otra cuenta=2 : ");
scanf("%d",&opc1);
if(opc1==1||opc1==0){
gotoxy(15,28);printf("Ingrese el monto a modicifar
: ");
scanf("%d",&monto);
if(opc1==1){
cont1=0;
while(monto!=auxc[cont1][2]){
cont1++;
gotoxy(92,8+cont1);printf("%d",&auxc[cont1][2]);
}
k=auxc[cont1][0];
j=auxc[cont1][1];
part=part-monto;
gotoxy(72,8+cont1);printf(" ");
gotoxy(72,8+cont1);scanf("%d",&monto);
auxc[cont1][2]=monto;
movimientos[0][k][j]=monto;
part+=monto;
}
if(opc1==0){
cont1=0;
while(monto!=auxa[cont1][2]){
cont1++;
}
k=auxa[cont1][0];
j=auxa[cont1][1];
part1=part1-monto;
gotoxy(87,8+cont1);printf(" ");
gotoxy(87,8+cont1);scanf("%d",&monto);
auxa[cont1][2]=monto;
movimientos[1][k][j]=monto;
part1+=monto;
}
}else{
opc2=2;
y--;
}
}
if(part==part1){
gotoxy(15,27);printf("Existe partida doble ...");
}
}
if(part==part1){
gotoxy(15,27);printf(" ");
gotoxy(15,26);printf(" ");
gotoxy(15,28);printf(" ");
gotoxy(15,29);printf(" ");
gotoxy(15,30);printf(" ");
gotoxy(15,27);printf("Desea guardar la informacion Si=1, No=0 : ");
scanf("%d",&opc1);
if(opc1==1){
gotoxy(15,28);printf("Informacion guardada exitosamente
...");
gotoxy(15,29);printf("Pulse una tecla para continuar...");
getch();
}else{
for(i=0;i<=y;i++);{
k=auxc[i][0];
j=auxc[i][1];
if(auxc[i][2]!=0){
movimientos[0][k][j]=0;
}
k=auxa[i][0];
j=auxa[i][1];
if(auxa[i][2]!=0){
movimientos[1][k][j]=0;
}
gotoxy(15,28);printf("Pulse una tecla para
continuar...");
}
}
opc2=0;
}
}
a++;
b++;
y++;
}while(opc2!=0);
}
void crear_cuenta(int y,char cuenta[]){
//activo corculante
gotoxy(12,8+y);gets(cuenta);
if(!strcmp(cuenta,"100-10-01")){
gotoxy(24,8+y);puts(activosc[0]);
cont=0;
}
if(!strcmp(cuenta,"100-10-02")){
gotoxy(24,8+y);puts(activosc[1]);
cont=1;
}
if(!strcmp(cuenta,"100-10-03")){
gotoxy(24,8+y);puts(activosc[2]);
cont=2;
}
if(!strcmp(cuenta,"100-10-04")){
gotoxy(24,8+y);puts(activosc[3]);
cont=3;
}
if(!strcmp(cuenta,"100-10-05")){
gotoxy(24,8+y);puts(activosc[4]);
cont=4;
}
if(!strcmp(cuenta,"100-10-06")){
gotoxy(24,8+y);puts(activosc[5]);
cont=5;
}
if(!strcmp(cuenta,"100-10-07")){
gotoxy(24,8+y);puts(activosc[6]);
cont=6;
}
if(!strcmp(cuenta,"100-10-08")){
gotoxy(24,8+y);puts(activosc[7]);
cont=7;
}
if(!strcmp(cuenta,"100-10-09")){
gotoxy(24,8+y);puts(activosc[8]);
cont=8;
}
if(!strcmp(cuenta,"100-10-10")){
gotoxy(24,8+y);puts(activosc[9]);
cont=9;
}
//activo fijo
if(!strcmp(cuenta,"100-20-01")){
gotoxy(24,8+y);puts(activosf[0]);
cont=10;
}
if(!strcmp(cuenta,"100-20-02")){
gotoxy(24,8+y);puts(activosf[1]);
cont=11;
}
if(!strcmp(cuenta,"100-20-03")){
gotoxy(24,8+y);puts(activosf[2]);
cont=12;
}
if(!strcmp(cuenta,"100-20-04")){
gotoxy(24,8+y);puts(activosf[3]);
cont=13;
}
if(!strcmp(cuenta,"100-20-05")){
gotoxy(24,8+y);puts(activosf[4]);
cont=14;
}
if(!strcmp(cuenta,"100-20-06")){
gotoxy(24,8+y);puts(activosf[5]);
cont=15;
}
if(!strcmp(cuenta,"100-20-07")){
gotoxy(24,8+y);puts(activosf[6]);
cont=16;
}
//activo diferido
if(!strcmp(cuenta,"100-30-01")){
gotoxy(24,8+y);puts(activosd[0]);
cont=17;
}
if(!strcmp(cuenta,"100-30-02")){
gotoxy(24,8+y);puts(activosd[1]);
cont=18;
}
if(!strcmp(cuenta,"100-30-03")){
gotoxy(24,8+y);puts(activosd[2]);
cont=19;
}
if(!strcmp(cuenta,"100-30-04")){
gotoxy(24,8+y);puts(activosd[3]);
cont=20;
}
if(!strcmp(cuenta,"100-30-05")){
gotoxy(24,8+y);puts(activosd[4]);
cont=21;
}
if(!strcmp(cuenta,"100-30-06")){
gotoxy(24,8+y);puts(activosd[5]);
cont=22;
}
if(!strcmp(cuenta,"100-30-07")){
gotoxy(24,8+y);puts(activosd[6]);
cont=23;
}
if(!strcmp(cuenta,"100-30-08")){
gotoxy(24,8+y);puts(activosd[7]);
cont=24;
}
if(!strcmp(cuenta,"100-30-09")){
gotoxy(24,8+y);puts(activosd[8]);
cont=25;
}
if(!strcmp(cuenta,"100-30-10")){
gotoxy(24,8+y);puts(activosd[9]);
cont=26;
}
//pasivo circulante
if(!strcmp(cuenta,"200-10-01")){
gotoxy(24,8+y);puts(pasivoc[0]);
cont=27;
}
if(!strcmp(cuenta,"200-10-02")){
gotoxy(24,8+y);puts(pasivoc[1]);
cont=28;
}
if(!strcmp(cuenta,"200-10-03")){
gotoxy(24,8+y);puts(pasivoc[2]);
cont=29;
}
if(!strcmp(cuenta,"200-10-04")){
gotoxy(24,8+y);puts(pasivoc[3]);
cont=30;
}
if(!strcmp(cuenta,"200-10-05")){
gotoxy(24,8+y);puts(pasivoc[4]);
cont=31;
}
if(!strcmp(cuenta,"200-10-06")){
gotoxy(24,8+y);puts(pasivoc[5]);
cont=32;
}
if(!strcmp(cuenta,"200-10-07")){
gotoxy(24,8+y);puts(pasivoc[6]);
cont=33;
}
if(!strcmp(cuenta,"200-10-08")){
gotoxy(24,8+y);puts(pasivoc[7]);
cont=34;
}
//pasivo fijo
if(!strcmp(cuenta,"200-20-01")){
gotoxy(24,8+y);puts(pasivof[0]);
cont=35;
}
if(!strcmp(cuenta,"200-20-02")){
gotoxy(24,8+y);puts(pasivof[1]);
cont=36;
}
if(!strcmp(cuenta,"200-20-03")){
gotoxy(24,8+y);puts(pasivof[2]);
cont=37;
}
//pasivo diferido
if(!strcmp(cuenta,"200-30-01")){
gotoxy(24,8+y);puts(pasivod[0]);
cont=38;
}
if(!strcmp(cuenta,"200-30-02")){
gotoxy(24,8+y);puts(pasivod[1]);
cont=39;
}
//Estados de resultado
if(!strcmp(cuenta,"400-10-01")){
gotoxy(24,8+y);puts(otros[0]);
cont=40;
}
if(!strcmp(cuenta,"400-10-02")){
gotoxy(24,8+y);puts(otros[1]);
cont=41;
}
if(!strcmp(cuenta,"400-10-03")){
gotoxy(24,8+y);puts(otros[2]);
cont=42;
}
if(!strcmp(cuenta,"400-10-04")){
gotoxy(24,8+y);puts(otros[3]);
cont=43;
}
if(!strcmp(cuenta,"400-10-05")){
gotoxy(24,8+y);puts(otros[4]);
cont=44;
}
if(!strcmp(cuenta,"400-10-06")){
gotoxy(24,8+y);puts(otros[5]);
cont=45;
}
if(!strcmp(cuenta,"400-10-07")){
gotoxy(24,8+y);puts(otros[6]);
cont=46;
}
if(!strcmp(cuenta,"400-10-08")){
gotoxy(24,8+y);puts(otros[7]);
cont=47;
}
if(!strcmp(cuenta,"400-10-09")){
gotoxy(24,8+y);puts(otros[8]);
cont=48;
}
if(!strcmp(cuenta,"400-10-10")){
gotoxy(24,8+y);puts(otros[9]);
cont=49;
}
if(!strcmp(cuenta,"400-10-11")){
gotoxy(24,8+y);puts(otros[10]);
cont=50;
}
if(!strcmp(cuenta,"400-10-12")){
gotoxy(24,8+y);puts(otros[11]);
cont=51;
}
//capital social
if(!strcmp(cuenta,"300-10-01")){
gotoxy(24,8+y);puts(capital[0]);
cont=52;
}
}
void balance_comprobacion(){
 int i;
 total1=0;
 total2=0;
 total3=0;
 total4=0;
 for(i=0;i<91;i++){
 gotoxy(8+i,3);printf("_");
 gotoxy(8+i,7);printf("_");
 gotoxy(8+i,34);printf("_");
 }
for(i=0;i<53;i++){
 gotoxy(46+i,5);printf("_");
 }
for(i=0;i<29;i++){
 gotoxy(8,4+i);printf("%c",179);
 gotoxy(46,4+i);printf("%c",179);
 gotoxy(59,6+i);printf("%c",179);
 gotoxy(72,4+i);printf("%c",179);
 gotoxy(85,6+i);printf("%c",179);
 gotoxy(98,4+i);printf("%c",179);
 }
for(i=0;i<6;i++){
 gotoxy(8,29+i);printf("%c",179);
 gotoxy(46,29+i);printf("%c",179);
 gotoxy(72,29+i);printf("%c",179);
 gotoxy(98,29+i);printf("%c",179);
}
gotoxy(40,2);printf("Balanza de Comprobacion");
 gotoxy(25,5);printf("Cuenta");
 gotoxy(55,4);printf("Movimiemto");
 gotoxy(84,4);printf("Saldo");
 gotoxy(49,6);printf("Cargo");
 gotoxy(63,6);printf("Abono");
 gotoxy(75,6);printf("Cargo");
 gotoxy(89,6);printf("Abono");
 cont=0;
 for(i=0;i<53;i++){
 if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
 if(i<10){
 gotoxy(10,8+cont);puts(activosc[i]);
}
if(i>=10&&i<17){
gotoxy(10,8+cont);puts(activosf[i-10]);
}
if(i>=17&&i<27){
gotoxy(10,8+cont);puts(activosd[i-17]);
}
 if(i>=27&&i<35){
 gotoxy(10,8+cont);puts(pasivoc[i-27]);
}
if(i>=35&&i<38){
gotoxy(10,8+cont);puts(pasivof[i-35]);
}
if(i>=38&&i<40){
gotoxy(10,8+cont);puts(pasivod[i-38]);
}
if(i>=40&&i<52){
gotoxy(10,8+cont);puts(otros[i-40]);
}
if(i==52){
gotoxy(10,8+cont);puts(capital[i-52]);
}
cont1=0;
suma1=0;
while(movimientos[0][i][cont1]!=0){
suma1+=movimientos[0][i][cont1];
cont1++;
}
gotoxy(49,8+cont);printf("%d",suma1);
total1+=suma1;
cont1=0;
suma=0;
while(movimientos[1][i][cont1]!=0){
suma+=movimientos[1][i][cont1];
cont1++;
}
gotoxy(61,8+cont);printf("%d",suma);
total2+=suma;
if(suma1>suma){
total=suma1-suma;
gotoxy(75,8+cont);printf("%d",total);
aux[i]=total;
total3+=aux[i];
}
if(suma1<suma){
total=suma-suma1;
gotoxy(89,8+cont);printf("%d",total);
aux[i]=total;
total4+=aux[i];
}
cont++;
}
}
gotoxy(10,9+cont);printf("Total");
gotoxy(49,9+cont);printf("%d",total1);
gotoxy(61,9+cont);printf("%d",total2);
gotoxy(75,9+cont);printf("%d",total3);
gotoxy(89,9+cont);printf("%d",total4);
 }
void balanze_general(){
 int i;
 for(i=0;i<91;i++){
 gotoxy(8+i,5);printf("_");
 gotoxy(8+i,7);printf("_");
 gotoxy(8+i,35);printf("_");
 }
for(i=0;i<30;i++){
 gotoxy(8,6+i);printf("%c",179);
 gotoxy(46,6+i);printf("%c",179);
 gotoxy(59,6+i);printf("%c",179);
 gotoxy(72,6+i);printf("%c",179);
 gotoxy(85,6+i);printf("%c",179);
 gotoxy(98,6+i);printf("%c",179);
 }
gotoxy(40,4);printf("Balance General ");
 gotoxy(10,6);printf("Cuenta");
 gotoxy(52,6);printf("1");
 gotoxy(65,6);printf("2");
 gotoxy(76,6);printf("3");
 gotoxy(90,6);printf("4");
 gotoxy(10,8);printf("Activos");
gotoxy(10,9);printf("Activo circulante");
cont=0;
for(i=0;i<10;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,10+cont);puts(activosc[i]);
gotoxy(65,10+cont);printf("%d",aux[i]);
cont++;
while(movimientos[0][i][cont1]!=0){
suma1+=movimientos[0][i][cont1];
cont1++;
}
total+=suma1;
}
}
// gotoxy(10,10+cont);printf("Total de activo circulante");
// gotoxy(76,10+cont);printf("%d",total);
gotoxy(10,11+cont);printf("Activo fijo");
for(i=10;i<17;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,12+cont);puts(activosf[i-10]);
gotoxy(65,12+cont);printf("%d",aux[i]);
cont++;
while(movimientos[0][i][cont1]!=0){
suma1+=movimientos[0][i][cont1];
cont1++;
}
}
}
//gotoxy(10,12+cont);printf("Total de activo fijo");
//gotoxy(76,12+cont);printf("%d",suma1);
gotoxy(10,13+cont);printf("Activo diferido");
for(i=17;i<27;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,14+cont);puts(activosd[i-17]);
gotoxy(65,14+cont);printf("%d",aux[i]);
cont++;
while(movimientos[0][i][cont1]!=0){
suma1+=movimientos[0][i][cont1];
cont1++;
}
}
}
// gotoxy(10,14+cont);printf("Total de activo diferido");
//otoxy(76,14+cont);printf("%d",suma1);
gotoxy(10,16+cont);printf("Pasivo circulante");
for(i=27;i<35;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,17+cont);puts(pasivoc[i-27]);
gotoxy(65,17+cont);printf("%d",aux[i]);
cont++;
}
}
gotoxy(10,17+cont);printf("Pasivo fijo");
for(i=35;i<38;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,18+cont);puts(pasivof[i-35]);
gotoxy(65,18+cont);printf("%d",aux[i]);
cont++;
}
}
gotoxy(10,18+cont);printf("Pasivo diferido");
for(i=38;i<40;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,19+cont);puts(pasivod[i-38]);
gotoxy(65,19+cont);printf("%d",aux[i]);
cont++;
}
}
gotoxy(10,19+cont);printf("Capital social");
for(i=52;i<53;i++){
if(movimientos[0][i][0]!=0||movimientos[1][i][0]!=0){
gotoxy(12,20+cont);puts(capital[i-52]);
gotoxy(65,20+cont);printf("%d",aux[i]);
cont++;
}
}
 }
void estado_resultados(){
 int i,suma1,suma2,suma3,suma4,res,tot1,tot2,tot3,tot4;
 for(i=0;i<91;i++){
 gotoxy(8+i,2);printf("_");
 gotoxy(8+i,4);printf("_");
 gotoxy(8+i,30);printf("_");
 }
for(i=0;i<28;i++){
 gotoxy(8,3+i);printf("%c",179);
 gotoxy(46,3+i);printf("%c",179);
 gotoxy(59,3+i);printf("%c",179);
 gotoxy(72,3+i);printf("%c",179);
 gotoxy(85,3+i);printf("%c",179);
 gotoxy(98,3+i);printf("%c",179);
 }
gotoxy(40,1);printf("Estado de comprobacion");
 gotoxy(10,3);printf("Cuenta");
 gotoxy(52,3);printf("1");
 gotoxy(65,3);printf("2");
 gotoxy(76,3);printf("3");
 gotoxy(90,3);printf("4");
 gotoxy(11,5);printf("Ventas totales");
 gotoxy(11,6);printf("Dev. y reb. s/venta");
 gotoxy(11,7);printf("Utilidad neto");
 gotoxy(11,8);printf("Compras");
 gotoxy(11,9);printf("Gastos de compra");
 gotoxy(11,10);printf("Compras totales");
 gotoxy(11,11);printf("Dev. y reb. s/compras");
 gotoxy(11,12);printf("Compras neto");
 gotoxy(11,13);printf("Inventario inicial");
 gotoxy(11,14);printf("Total de mercancias");
 gotoxy(11,15);printf("Inventario final");
 gotoxy(11,16);printf("Costo de Venta");
 gotoxy(11,17);printf("Utilidad bruta");
 gotoxy(11,18);printf("Gastos generales");
 gotoxy(11,19);printf("Utilidad operativa");
 gotoxy(11,20);printf("Otros productos");
 gotoxy(11,21);printf("Otros gastos");
 gotoxy(11,22);printf("Utilidades antes dinancieros");
 gotoxy(11,23);printf("Productos financieros");
 gotoxy(11,24);printf("Gastos financieros");
 gotoxy(11,25);printf("Utilidad antes impuestos");
 gotoxy(11,26);printf("Impuestos");
 gotoxy(11,27);printf("Utilidad neto del ejercicio");

cont1=0;
suma1=0;
while(movimientos[0][40][cont1]!=0){
suma1+=movimientos[0][40][cont1];
cont1++;
}
gotoxy(50,5);printf("%d",suma1);
cont1=0;
suma2=0;
while(movimientos[0][41][cont1]!=0){
suma2+=movimientos[0][41][cont1];
cont1++;
}
gotoxy(50,6);printf("%d",suma2);
tot1=suma1-suma2;
//total1
gotoxy(62,7);printf("%d",tot1);

 cont1=0;
suma1=0;
while(movimientos[0][42][cont1]!=0){
suma1+=movimientos[0][42][cont1];
cont1++;
}
gotoxy(50,8);printf("%d",suma1);
cont1=0;
suma2=0;
while(movimientos[0][43][cont1]!=0){
suma2+=movimientos[0][43][cont1];
cont1++;
}
gotoxy(50,9);printf("%d",suma2);
tot2=suma1+suma2;
//total2
gotoxy(50,10);printf("%d",tot2);
cont1=0;
suma1=0;
while(movimientos[0][44][cont1]!=0){
suma1+=movimientos[0][44][cont1];
cont1++;
}
gotoxy(50,11);printf("%d",suma1);
tot3=tot2-suma1;
gotoxy(50,12);printf("%d",tot3);
//gggg
 cont1=0;
suma1=0;
while(movimientos[0][45][cont1]!=0){
suma1+=movimientos[0][45][cont1];
cont1++;
}
gotoxy(50,13);printf("%d",suma1);
tot4=tot3+suma1;
gotoxy(50,14);printf("%d",tot4);
//total4
cont1=0;
suma1=0;
while(movimientos[0][46][cont1]!=0){
suma1+=movimientos[0][46][cont1];
cont1++;
}
gotoxy(50,15);printf("%d",suma1);
tot2=tot4-suma1;
aux[49]=tot2;
gotoxy(65,16);printf("%d",tot2);
//total inventario
tot3=tot1-tot2;
gotoxy(74,17);printf("%d",tot3);
cont1=0;
suma1=0;
while(movimientos[0][47][cont1]!=0){
suma1+=movimientos[0][47][cont1];
cont1++;
}
gotoxy(74,18);printf("%d",suma1);
tot1=tot3-suma1;
gotoxy(90,19);printf("%d",tot1);
cont1=0;
suma1=0;
while(movimientos[0][48][cont1]!=0){
suma1+=movimientos[0][48][cont1];
cont1++;
}
gotoxy(90,20);printf("%d",suma1);
cont1=0;
suma2=0;
while(movimientos[0][49][cont1]!=0){
suma2+=movimientos[0][49][cont1];
cont1++;
}
gotoxy(90,21);printf("%d",suma2);
tot2=tot1+suma1+suma2;
gotoxy(90,22);printf("%d",tot2);
cont1=0;
suma1=0;
while(movimientos[0][50][cont1]!=0){
suma1+=movimientos[0][50][cont1];
cont1++;
}
gotoxy(90,23);printf("%d",suma1);
cont1=0;
suma2=0;
while(movimientos[0][51][cont1]!=0){
suma2+=movimientos[0][51][cont1];
cont1++;
}
gotoxy(90,24);printf("%d",suma2);
tot4=tot2-suma1-suma2;
gotoxy(90,25);printf("%d",tot4);
tot3=(tot4*.10);
tot1=tot4-tot3;
tot2=tot1*.35;
gotoxy(90,26);printf("%d",tot3+tot2);
aux[58]=tot3+tot2;
tot4=tot1-tot2;
gotoxy(90,27);printf("%d",tot4);
aux[57]=tot4;
 }
void cierre_ejercicio(){
int cont1,suma1;
for(k=0;k<7;k++){
for(j=0;j<2;j++){
for(i=0;i<40;i++){
gotoxy(2+(i+(j*48)),2+(k*5));printf("_");
gotoxy(2+(i+(j*48)),5+(k*5));printf("_");
}
for(i=0;i<3;i++){
gotoxy(2+(j*48),3+(i+(k*5)));printf("%c",179);
gotoxy(25+(j*48),3+(i+(k*5)));printf("%c",179);
gotoxy(34+(j*48),3+(i+(k*5)));printf("%c",179);
gotoxy(42+(j*48),3+(i+(k*5)));printf("%c",179);
}
}
}
gotoxy(3,3);printf("Ventas");
gotoxy(6,4);printf("Dev. s/venta");
cont1=0;
suma1=0;
while(movimientos[0][37][cont1]!=0){
suma1+=movimientos[0][37][cont1];
cont1++;
}
gotoxy(26,3);printf("%d",suma1);
gotoxy(35,4);printf("%d",suma1);
gotoxy(51,3);printf("Compras");
gotoxy(54,4);printf("Gastos compra");
cont1=0;
suma1=0;
while(movimientos[0][39][cont1]!=0){
suma1+=movimientos[0][39][cont1];
cont1++;
}
gotoxy(76,3);printf("%d",suma1);
gotoxy(84,4);printf("%d",suma1);
gotoxy(3,8);printf("Dev. s/Compra");
gotoxy(6,9);printf("Compras");
cont1=0;
suma1=0;
while(movimientos[0][40][cont1]!=0){
suma1+=movimientos[0][40][cont1];
cont1++;
}
gotoxy(26,8);printf("%d",suma1);
gotoxy(35,9);printf("%d",suma1);
gotoxy(51,8);printf("Compras");
gotoxy(54,9);printf("Inventario inicial");
cont1=0;
suma1=0;
while(movimientos[0][41][cont1]!=0){
suma1+=movimientos[0][41][cont1];
cont1++;
}
gotoxy(76,8);printf("%d",suma1);
gotoxy(84,9);printf("%d",suma1);
gotoxy(3,13);printf("Inventario final");
gotoxy(6,14);printf("Compras");
cont1=0;
suma1=0;
while(movimientos[0][42][cont1]!=0){
suma1+=movimientos[0][42][cont1];
cont1++;
}
gotoxy(26,13);printf("%d",suma1);
gotoxy(35,14);printf("%d",suma1);
gotoxy(51,13);printf("Ventas");
gotoxy(54,14);printf("Compras");
gotoxy(76,13);printf("%d",aux[49]);
gotoxy(84,14);printf("%d",aux[49]);
gotoxy(3,18);printf("Ventas");
gotoxy(6,19);printf("Gastos generales");
cont1=0;
suma1=0;
while(movimientos[0][43][cont1]!=0){
suma1+=movimientos[0][43][cont1];
cont1++;
}
gotoxy(26,18);printf("%d",suma1);
gotoxy(35,19);printf("%d",suma1);
gotoxy(51,18);printf("Otros productos");
gotoxy(54,19);printf("Ventas");
cont1=0;
suma1=0;
while(movimientos[0][44][cont1]!=0){
suma1+=movimientos[0][44][cont1];
cont1++;
}
gotoxy(76,18);printf("%d",suma1);
gotoxy(84,19);printf("%d",suma1);
gotoxy(3,23);printf("Ventas");
gotoxy(6,24);printf("Gastos financieros");
cont1=0;
suma1=0;
while(movimientos[0][47][cont1]!=0){
suma1+=movimientos[0][47][cont1];
cont1++;
}
gotoxy(26,23);printf("%d",suma1);
gotoxy(35,24);printf("%d",suma1);
gotoxy(51,23);printf("Ventas");
gotoxy(54,24);printf("Impuestos");
gotoxy(76,23);printf("%d",aux[48]);
gotoxy(84,24);printf("%d",aux[48]);
gotoxy(3,23);printf("Ventas");
gotoxy(6,24);printf("Gastos financieros");
gotoxy(51,23);printf("Ventas");
gotoxy(54,24);printf("Impuestos");
gotoxy(3,28);printf("Ventas");
gotoxy(6,29);printf("Otros gastos");
gotoxy(51,28);printf("Productos financieros");
gotoxy(54,29);printf("Ventas");
gotoxy(3,33);printf("Utilidad del ejercicio");
gotoxy(6,34);printf("Ventas");
gotoxy(26,33);printf("%d",aux[47]);
gotoxy(35,34);printf("%d",aux[47]);
}
void tablaesquema_mayor(){
for(k=0;k<3;k++){
for(j=0;j<4;j++){
for(i=0;i<18;i++){
gotoxy(4+(i+(j*28)),5+(k*10));printf("_");
}
for(i=0;i<8;i++){
gotoxy(12+(j*28),6+(i+(k*10)));printf("%c",179);
}
}
}
}
void esquema_mayor1(){
int contad=0,a,b,c;
gotoxy(7,4);printf("Caja");
gotoxy(34,4);printf("Bancos");
gotoxy(60,4);printf("Inverciones Tem.");
gotoxy(90,4);printf("Mercancias");
gotoxy(7,14);printf("Clientes");
gotoxy(34,14);printf("Doc. por cobrar");
gotoxy(60,14);printf("Deudores diversos");
gotoxy(90,14);printf("Anticipo prov.");
gotoxy(7,24);printf("IVA acreditable");
gotoxy(34,24);printf("IVA pend acreditar");
gotoxy(60,24);printf("Terrenos");
gotoxy(90,24);printf("Edificios");
for(a=0;a<3;a++){
for(b=0;b<4;b++){
for(c=0;c<10;c++){
if(movimientos[0][contad][c]!=0){
gotoxy(5+(b*28),6+(c+(a*10)));printf("%d",movimientos[0][contad][c]);
}
}
for(c=0;c<10;c++){
if(movimientos[1][contad][c]!=0){
gotoxy(13+(b*28),6+(c+(a*10)));printf("%d",movimientos[1][contad][c]);
}
}
contad++;
}
}
}
void esquema_mayor2(){
int contad=11,a,b,c;
gotoxy(5,4);printf("Movivliario y Eq");
gotoxy(32,4);printf("Eq. de computo");
gotoxy(60,4);printf("Eq. de reparto");
gotoxy(88,4);printf("Dep. en grantia");
gotoxy(5,14);printf("Inver. permanentes");
gotoxy(32,14);printf("ast.inv. y des.");
gotoxy(60,14);printf("Gast. en et. preop.");
gotoxy(88,14);printf("Gast. de mercadotecnia");
gotoxy(5,24);printf("Gast. de org.");
gotoxy(32,24);printf("Gast. de inst.");
gotoxy(60,24);printf("Pap. y utiles");
gotoxy(88,24);printf("Prop. y publicidad");
for(a=0;a<3;a++){
for(b=0;b<4;b++){
for(c=0;c<10;c++){
if(movimientos[0][contad][c]!=0){
gotoxy(5+(b*28),6+(c+(a*10)));printf("%d",movimientos[0][contad][c]);
}
}
for(c=0;c<10;c++){
if(movimientos[1][contad][c]!=0){
gotoxy(13+(b*28),6+(c+(a*10)));printf("%d",movimientos[1][contad][c]);
}
}
contad++;
}
}
}
void esquema_mayor3(){
int contad=23,a,b,c;
gotoxy(5,4);printf("Primas de seg.");
gotoxy(32,4);printf("Ren. pag. por ant.");
gotoxy(60,4);printf("Int. pag. por ant.");
gotoxy(88,4);printf("Proveedores");
gotoxy(5,14);printf("Documento por pagar");
gotoxy(32,14);printf("Acredores diversos");
gotoxy(60,14);printf("Anticipo a clientes");
gotoxy(88,14);printf("Gastos pend. de pago");
gotoxy(5,24);printf("Imp. pend. de pago");
gotoxy(32,24);printf("IVA pend pago");
gotoxy(60,24);printf("Retencion terceros");
gotoxy(88,24);printf("Ipot. por pag. a acred.");
for(a=0;a<3;a++){
for(b=0;b<4;b++){
for(c=0;c<10;c++){
if(movimientos[0][contad][c]!=0){
gotoxy(5+(b*28),6+(c+(a*10)));printf("%d",movimientos[0][contad][c]);
}
}
for(c=0;c<10;c++){
if(movimientos[1][contad][c]!=0){
gotoxy(13+(b*28),6+(c+(a*10)));printf("%d",movimientos[1][contad][c]);
}
}
contad++;
}
}
}
void esquema_mayor4(){
int contad=35,a,b,c;
gotoxy(5,4);printf("Doc. pag. a lar. plazo");
gotoxy(32,4);printf("Cuen. pag. a lar. plazo");
gotoxy(60,4);printf("Rent. cob. por anticipado");
gotoxy(88,4);printf("Int. cobradas por ant.");
gotoxy(5,14);printf("ventas");
gotoxy(32,14);printf("dev y reb. ventas");
gotoxy(60,14);printf("compras");
gotoxy(88,14);printf("Gastos de compra");
gotoxy(5,24);printf("Idev. y reb. compras");
gotoxy(32,24);printf("inventario inicial");
gotoxy(60,24);printf("inventario final");
gotoxy(88,24);printf("gastos generales");
for(a=0;a<3;a++){
for(b=0;b<4;b++){
for(c=0;c<10;c++){
if(movimientos[0][contad][c]!=0){
gotoxy(5+(b*28),6+(c+(a*10)));printf("%d",movimientos[0][contad][c]);
}
}
for(c=0;c<10;c++){
if(movimientos[1][contad][c]!=0){
gotoxy(13+(b*28),6+(c+(a*10)));printf("%d",movimientos[1][contad][c]);
}
}
contad++;
}
}
}
void esquema_mayor5(){
int contad=47,a,b,c;
gotoxy(5,4);printf("Otros productos");
gotoxy(32,4);printf("Otros gastos");
gotoxy(60,4);printf("Productos Financieros");
gotoxy(88,4);printf("Gastos financieros");
gotoxy(5,14);printf("capital social");
for(a=0;a<3;a++){
for(b=0;b<4;b++){
for(c=0;c<10;c++){
if(movimientos[0][contad][c]!=0){
gotoxy(5+(b*28),6+(c+(a*10)));printf("%d",movimientos[0][contad][c]);
}
}
for(c=0;c<10;c++){
if(movimientos[1][contad][c]!=0){
gotoxy(13+(b*28),6+(c+(a*10)));printf("%d",movimientos[1][contad][c]);
}
}
contad++;
}
}
}
void cierre_esquema(){
for(k=0;k<3;k++){
for(j=0;j<5;j++){
for(i=0;i<14;i++){
gotoxy(4+(i+(j*20)),2+(k*10));printf("_");
}
for(i=0;i<6;i++){
gotoxy(10+(j*20),3+(i+(k*10)));printf("%c",179);
}
}
}
gotoxy(5,1);printf("Ventas");
gotoxy(26,1);printf("Dev. S/ventas");
gotoxy(47,1);printf("Compras");
gotoxy(65,1);printf("Gastos compra");
gotoxy(6,11);printf("Dev. s/compras");
gotoxy(26,11);printf("Compras neto");
gotoxy(47,11);printf("Inventario inicial");
gotoxy(65,11);printf("Inventario final");
gotoxy(4,21);printf("Gastos generales");
gotoxy(26,21);printf("Otros productos");
gotoxy(50,21);printf("Otros gastos");
gotoxy(73,21);printf("Productos financieros");
gotoxy(83,1);printf("Gastos financieros ");
gotoxy(83,11);printf("Impuestos");
gotoxy(83,21);printf("Utilidad del ejer.");
}