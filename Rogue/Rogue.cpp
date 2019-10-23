#include<windows.h>//  -- Rogue Like --
#include<iostream> //  By: Michael Pelz
#define R(o) !(!(GetKeyState((o))&256))
#define O SetConsoleCursorPosition
#define G GetStdHandle(-11)
#define U(o,p) O(G,(o));std::wcout<<(p)
#define E(o,x) x=(o);while (x--){
struct V:COORD{V(){}V(int x,int y){X=x;Y=
y;}bool operator==(COORD& o){return o.X==
X&&o.Y==Y;}};std::wstring d,f,i,j,k,l,n,m
,p,q,s,t,v;int r,o,g,u,e,z,x,y;V A,Z[99],
GA,UN,T,L,ET;void B(V*v){x=1;while(x>0){x
=rand()%11*2+7;y=rand()%10*2+7;e=y*r+r+x;
if(m[e]!=l[0]){*v={x,y+1};x=0;}}}void N()
{o++;T={3,3};j=36;k=n;m=p+v;E(26,e)z=1;y=
rand()%3+2;q=l;E(3,x)if(x==2&&e>24)q+=t;
else{if(rand()%5==0){q+=s;z--;}else{q+=t;
z=1;}}if(z<0&&x>0){q+=t;x--;}}q+=l;while(
--y&&e){m+=q;e--;}m+=q;}m+=v;m+=p;B(&GA);
B(&UN);E(o-1,g)B(&Z[g]);}E(30,g)A={0,g};U
(A,m.substr(r*g,r));}}void M(V*z,V d){U(
*z,n);A={z->X+d.X,z->Y+d.Y};if(m[A.X+A.Y*
r]!=l[0]){*z=A;}}bool C(){x=0;E(o,g)x=T==
Z[g]?1:x;}return x;}int main(){i=219;l=
178;n=176;f=234;L={1,1};r=32;ET={30,28};u
=0;srand(1);e=10;E(r,g)p+=l;}E(e,g)s+=l;}
E(e,g)t+=n;}v=l;E(30,g)v+=n;}v+=l;while(!
R(27)){o=0;A={37,2};U(A,"GAUNTLET");N();
while(!R(27)&&!C()){u++;if(u>21){E(o-1,g)
M(&Z[g],{rand()%3-1,rand()%3-1});}u=0;}A=
{37,5};U(A,"Level:");if(u%2)M(&T,{R(39)-R
(37),R(40)-R(38)});if(T==GA&&k==i)N();if(
T==UN){j=n;k=i;}if(T==L){T=ET;T.X--;}if(T
==ET){T=L;T.X++;}U(UN,j);U(GA,k);U(L,f);U
(ET,f);U(T,(char)129);d=79;if(u%10>5){d=
'o';}E(o-1,g)U(Z[g],d);}A={45,5};U(A,o);
Sleep(32);}A={37,2};U(A,"GameOver");
while(!R(13)&&!R(27)){Sleep(32);}}}
