#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct fraction{
	int num;
	int den;
};
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
struct fraction simplify(struct fraction f){
    int g = gcd(abs(f.num),f.den);
    f.num/=g;
    f.den/=g;
    return f;
}
void print_fraction(struct fraction f){
    f=simplify(f);
    if(f.den==1)
        printf("%d",f.num);
    else
        printf("%d/%d",f.num,f.den);
}

int main(){
	int degree,mode,function;
	printf("=======Calculus Calculator=======\n");
	printf("Please choose the function\n");
	printf("1.Polynomial Function\n");
	printf("2.Trigonometria Functions\n");
	while(1){
		scanf("%d",&mode);
		if(mode==1||mode==2)
			break;
		printf("Please enter a number, either 1 or 2\n");
	}
	system("cls");
	if(mode==1){//Polynomial Function
		printf("Please set your function\n");//Setting of Function
		printf("What is the degree of function?\n");
		scanf("%d",&degree);
		int PF[degree+1];
		printf("Please enter the coeffients of each term of the function in descending order\n");
		for(int i=0;i<=degree;i++){
			scanf("%d",&PF[i]);
		}printf("Your function is:");
		for(int i=0;i<degree;i++){
			if(i==degree-1&&PF[i]==1) printf("x");
			else if(PF[i]==1) printf("x^%d",degree-i);
			else if(i==degree-1&&PF[i]!=0) printf("%dx",PF[i]);
			else if(PF[i]!=0) printf("%dx^%d",PF[i],degree-i);
			if(PF[i+1]>0) printf("+");
		}if(PF[degree]!=0) printf("%d\n",PF[degree]);
		else printf("\n");
		printf("Please choose the mode you want\n");
		printf("1.Differentiation\n2.Integration\n");
		while(1){
			scanf("%d",&mode);
			if(mode==1||mode==2)
				break;
			printf("Please enter a number, either 1 or 2\n");
		}int PF2[degree];
		if(mode==1){//differentiation
			printf("1.First derivative\n2.Second derivative\n");
			while(1){
				scanf("%d",&mode);
				if(mode==1||mode==2)
					break;
				printf("Please enter a number, either 1 or 2\n");
			}for(int i=0;i<degree;i++)
				PF2[i]=PF[i]*(degree-i);
			if(mode==1){//first derivative
				for(int i=0;i<degree-1;i++){
					if(i==degree-2&&PF2[i]==1) printf("x");
					else if(PF2[i]==1) printf("x^%d",degree-1-i);
					else if(i==degree-2&&PF2[i]!=0) printf("%dx",PF2[i]);
					else if(PF2[i]!=0) printf("%dx^%d",PF2[i],degree-1-i);
					if(PF2[i+1]>0) printf("+");
				}if(PF2[degree-1]!=0) printf("%d\n",PF2[degree-1]);
				else printf("\n");
			}else{//second derivative
				int PF3[degree-1];
				for(int i=0;i<degree;i++)
					PF3[i]=PF2[i]*(degree-1-i);
				for(int i=0;i<degree-2;i++){
					if(i==degree-3&&PF3[i]==1) printf("x");
					else if(PF3[i]==1) printf("x^%d",degree-2-i);
					else if(i==degree-3&&PF3[i]!=0) printf("%dx",PF3[i]);
					else if(PF3[i]!=0) printf("%dx^%d",PF3[i],degree-2-i);
					if(PF3[i+1]>0) printf("+");
				}if(PF3[degree-2]!=0) printf("%d\n",PF3[degree-2]);
				else printf("\n");
			}
		}else{//integration
			printf("1.Definite integral\n2.Indefinite integral\n");
			while(1){
				scanf("%d",&mode);
				if(mode==1||mode==2)
					break;
				printf("Please enter a number, either 1 or 2\n");
			}
			if(mode==1){//definite integration
				int ll,ul;//lower limit, upper limit
				double result=0.0;
				printf("Please enter the lower limit\n");
				scanf("%d",&ll);
				printf("Please enter the upper limit\n");
				scanf("%d",&ul);
				for(int i=0;i<=degree;i++){
					int exp = degree-i+1;
                    result += PF[i] * (pow(ul, exp) - pow(ll, exp)) / exp;
				}
				printf("The value of the definite integral "); 
				printf("from %d to %d of the polynomial is = %.3f",ll,ul,result);
			}else{//indefinite integration
				for(int i=0;i<=degree;i++){
					int exp=degree-i+1;
        			if(PF[i]==0) continue;
       				if(i>0&&PF[i]>0) printf("+ ");
        			struct fraction coef;
       				coef.num=PF[i];
        			coef.den=exp;
        			print_fraction(coef);
        			printf("x");
        			if(exp!=1)printf("^%d",exp);
        			printf(" ");
				}
				printf("+ C\n");	
			}
		}
	}
	else{//Trigonometric Functions
		printf("Please set your degree\n");
		scanf("%d",&degree);
		float radians=degree*3.14159265358/180.0;
		printf("Please choose the mode you want\n");
		printf("1.Sine\n2.Cosine\n3.Tangent\n4.Cotangent\n5.Secant\n6.Cosecant\n");
		scanf("%d",&function);
		while(function<1||function>6){
			printf("Please enter a number from 1 to 6\n");
			scanf("%d",&function);
		}
		const char *F[6]={"sin","cos","tan","cot","sec","csc"};
		if(((function==3||function==5)&&degree%180==90)||((function==4||function==6)&&degree%180==0)){//undefined
			printf("%sθ is undefined in %d°\n",F[function-1],degree);
			return 0;			
		}
		else{
			if(function==1) printf("sin%d° = %.3f\n",degree,sin(radians));
 			else if(function==2) printf("cos%d° = %.3f\n",degree,cos(radians));
			else if(function==3) printf("tan%d° = %.3f\n",degree,tan(radians));
			else if(function==4) printf("cot%d° = %.3f\n",degree,1.0/tan(radians));
			else if(function==5) printf("sec%d° = %.3f\n",degree,1.0/cos(radians));
			else printf("csc%d° = %.3f\n",degree,1.0/sin(radians));	
		}
		printf("Please choose the mode you want\n");
		printf("1.Differentiation\n2.Integration\n");
		while(1){
			scanf("%d",&mode);
			if(mode==1||mode==2)
				break;
			printf("Please enter a number, either 1 or 2\n");
		}
		if(mode==1){//differentiation
			if(function==1) printf("d(sin%d°)/dθ = cos%d° = %.3f\n",degree,degree,cos(radians));
			else if(function==2) printf("d(cos%d°)/dθ = -sin%d° = %.3f\n",degree,degree,-sin(radians));
			else if(function==3) printf("d(tan%d°)/dθ = (sec%d°)^2 = %.3f\n",degree,degree,1.0/cos(radians)/cos(radians));
			else if(function==4) printf("d(cot%d°)/dθ = -(csc%d°)^2 = %.3f\n",degree,degree,-1.0/sin(radians)/sin(radians));
			else if(function==5) printf("d(sec%d°)/dθ = sec%d°(tan%d°) = %.3f\n",degree,degree,degree,1.0/cos(radians)*tan(radians));
			else printf("d(csc%d°)/dθ = -csc%d°(cot%d°) = %.3f\n",degree,degree,degree,-1.0/sin(radians)/tan(radians));
		}
		else{//integration
			if(function==1) printf("∫ sin%d° dθ = -cos%d° + C = %.3f + C\n",degree,degree,-cos(radians));
			else if(function==2) printf("∫ cos%d° dθ = sin%d° + C = %.3f + C\n",degree,degree,sin(radians));
			else if(function==3) printf("∫ tan%d° dθ = -ln∣cos%d°∣ + C = %.3f + C\n",degree,degree,-log(fabs(cos(radians))));
			else if(function==4) printf("∫ cot%d° dθ = ln∣sin%d°∣ + C = %.3f + C\n",degree,degree,log(fabs(sin(radians))));
			else if(function==5) printf("∫ sec%d° dθ = ln∣sec%d° + tan%d°∣ + C = %.3f + C\n",degree,degree,degree,log(fabs(1.0/cos(radians)+tan(radians))));
			else printf("∫ csc%d° dθ = ln∣csc%d° - cot%d°∣ + C = %.3f + C\n",degree,degree,degree,log(fabs(1.0/sin(radians)-1.0/tan(radians))));			
		}
	}
} 
