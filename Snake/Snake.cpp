#include<windows.h>//  --SMALL SNAKE--
#include<iostream> //             v0.1
#include<iomanip>  //  By: Michael Pelz
#define S(o) while((o)){
#define N SetConsoleCursorPosition(
#define A GetStdHandle(-11), 
#define K std::cout <<
#define E(o) (GetKeyState((o)) & 0x0100
short s, n, a, k, e, f, r, u, i, t;
struct v:COORD{v(){}v(short x,short y){
X=x;Y=y;}bool operator==(COORD &o){
return o.X==X&&o.Y==Y;}bool operator!=(
COORD &o) {return o.X != X || o.Y != Y;
}};bool _(v z, v p[]){a=u;while(a--)if(
a!=i&&z==p[a])return 1;return 0;}int 
main(){S(1)v q[70*30],w,y,z={0,0};s=70;
n=30;y=v(35,15);N A z);r=0;u=5;i=70*30+
1;S(--i)q[i]={s+5,2};}f=n;S(f--)t=s;S(
--t)K(f==n-1||f==0?"/":t==s-1?"/":" ");
}K"/\n";}n--;s--;srand(int(time(0)));w=
{rand()%(s-2)+2,rand()%(n-2)+2};N A w);
K"@";f = 0;N A z);S(!_(y, q)&&y.X>0
&& y.X < s && y.Y > 1 && y.Y < n)a=f==0
?!E(37))*2-!E(39))*2:!E(38))*5-!E(40))*
5;f=a==0?f:f==0?(!(a%2)?a/abs(a):0):!(a
%2)?f:0;r=a==0?r:r==0?(!(a%5)?a/abs(a):
0):!(a%5)?r:0;k=y.X+f>0&&y.X+f<s?f:0;e=
y.Y+r>1&&y.Y+r<n?r:0;y.X+=f;y.Y+=r;N A 
q[(i+1)%u]);K" ";i=(i+abs(k+e))%u;q[i]=
y;N A y);K"O";if(y==w){u+=u/5;t++;S(_(w
,q)||y==w)w={rand()%(s-2)+2,rand()%(n-2
)+2};}N A w);K"@";N A{s+3,2});K 
std::setw(3)<<t;}N A{s+6,2});Sleep(32);
}N A{s+3,3});K"Game Over";while(!E(13))
)Sleep(32);N A{s+3,3});K"         "; N 
A{s+3,2});K"   ";}}