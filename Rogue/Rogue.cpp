#include<windows.h>//  -- Rogue Like --
#include<iostream> //  By: Michael Pelz
#define R(o) !(!(GetKeyState((o))&256))
#define O SetConsoleCursorPosition
#define G GetStdHandle(-11)
#define U(o,p) O(G,(o));std::wcout<<(p)
#define E(o,x) x=(o);while (x--)
struct V:COORD{V(){}V(int x,int y){X=x;Y=
y;}bool operator==(COORD& o){return o.X==
X&&o.Y==Y;}};std::wstring a,b,c,d,f,h,i,j
,k,l,n,m,p,q,s,t,v;int r,o,g,u,e,z,w,x,y;
V GA,UN,T,L,ET,Z[99],A;void B(V*v){x=1;y=
1;while(x>0){x=rand()%11*2+7;y=rand()%10*
2+7;z=y*r+r+x;if(m[z]!=l[0]){*v={x,y+1};x
=0;}}}void N(){g++;T={3,3};j=h;k=n;m=p+v;
E(26,z){w=1;y=rand()%3+2;q=l;E(3,x){if(x
==2&&z>24)q+=t;else{if(rand()%5==0){q+=s;
--w;}else{q+=t;w=1;}}if(w<0&&x>0){q+=t;x
--;}}q+=l;while(--y&&z){m+=q;z--;}m+=q;}m
+=v;m+=p;B(&GA);B(&UN);E(g-1,u){B(&Z[u]);
}E(o,u){A={0,u};U(A,m.substr(r*u,r));}}
void M(V*z,V d){U(*z,n);A={z->X+d.X,z->Y+
d.Y};if(m[A.X+A.Y*r]!=l[0]){*z=A;}}bool C
(){E(g,u){if(T==Z[u])return 1;}return 0;}
int main(){c='o';h=36;b=79;i=219;l=178;n=
176;f=234;a=129;L={1,1};r=32;o=30;ET={30,
28};e=0;srand(1);z=10;E(r,u)p+=l;E(z,u)s
+=l;E(z,u)t+=n;v=l;E(30,u)v+=n;v+=l;while
(!R(27)){A={37,2};g=0;U(A,"GAUNTLET");N()
;while(!R(27)&&!C()){e++;if(e>21){E(g-1,u
){M(&Z[u],{rand()%3-1,rand()%3-1});}e=0;}
A={37,5};U(A,"Level:");if(e%2)M(&T,{R(39)
-R(37),R(40)-R(38)});if(T==GA&&k==i)N();
if(T==UN){j=n;k=i;}if(T==L){T=ET;T.X--;}
if(T==ET){T=L;T.X++;}U(UN,j);U(GA,k);U(L,
f);U(ET,f);U(T,a);d=b;if(e%10>5){d=c;}E(g
-1,u){U(Z[u],d);}A={45,5};U(A,g);Sleep(32
);}A={37,2};U(A,"GameOver");while(!R(13)
&&!R(27)){Sleep(32);}}}