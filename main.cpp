#include <iostream>
#include <cstring>
using namespace std;
void dibujo(int);
int juego(char*);

int main(int argc, char const *argv[]){
	int errores=0;
	char meow[5]="hola";
	errores=juego(meow);
	
	return 0;
}

void dibujo(int errores){
	if (errores==0){
		cout<<endl<<endl
	   <<"   +----+  "<<endl
	   <<"   |    |  "<<endl
	   <<"        |  "<<endl
	   <<"        |  "<<endl
	   <<"        |  "<<endl
	   <<"        |  "<<endl
	   <<"  ============="<<endl<<endl;
	}else if(errores==1){
		cout<<endl<<endl
	   <<"   +----+  "<<endl
	   <<"   |    |  "<<endl
	   <<"   O    |  "<<endl
	   <<"   |    |  "<<endl
	   <<"        |   "<<endl
	   <<"        |   "<<endl
	   <<"  ============="<<endl<<endl;
	}else if(errores==2){
		cout<<endl<<endl
	   <<"   +----+   "<<endl
	   <<"   |    |   "<<endl
	   <<"   O    |   "<<endl
	   <<"  /|    |   "<<endl
	   <<"        |   "<<endl
	   <<"        |   "<<endl
	   <<"  ============="<<endl<<endl;
	}else if(errores==3){
		cout<<endl<<endl
	   <<"   +----+  "<<endl
	   <<"   |    |  "<<endl
	   <<"   O    |  "<<endl
	   <<"  /|\\   |   "<<endl
	   <<"        |   "<<endl
	   <<"        |   "<<endl
	   <<"  ============="<<endl<<endl;
	}else if(errores==4){
		cout<<endl<<endl
	   <<"   +----+  "<<endl
	   <<"   |    |  "<<endl
	   <<"   O    |  "<<endl
	   <<"  /|\\   |  "<<endl
	   <<"    \\   |   "<<endl
	   <<"        |  "<<endl
	   <<"  ============"<<endl<<endl;
	}else if(errores==5){
		cout<<endl
		<<"  DERROTA!!! "<<endl
		<<"   +----+    "<<endl
		<<"   |    |    "<<endl
		<<"   O    |    "<<endl
		<<"  /|\\   |    "<<endl
		<<"  / \\   |    "<<endl
		<<"        |    "<<endl
		<<"  ============"<<endl<<endl;
	}
}

int juego(char* palabra){
	int falla=0;
	char mostrar[strlen(palabra)];
	strcpy(mostrar,palabra);
	for (int i = 0; i < strlen(palabra); i++){
		mostrar[i]='*';
	}
	for (int i = 0; i < strlen(palabra); ++i)
	{
		cout<<mostrar[i];
	}
	return 0;
}