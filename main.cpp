#include <iostream>
#include <cstring>
using namespace std;
void dibujo(int);
int juego(char*);

int main(int argc, char const *argv[]){
	int errores=0;
	int continuar;
	do{
		char meow[5]="hola";
		errores=juego(meow);
		if (errores==5){
			cout<<"Eres un loser! La palabra correcta era: "<<meow<<endl<<endl<<endl;
		}else{
			cout<<"Eres un ganador! Adivinastes la palabra: "<<meow<<"!!!!"<<endl<<endl<<endl;
		}
		cout<<"Desea continuar?"<<endl
			<<"1. Si"<<endl
			<<"2. No"<<endl;
		cin>>continuar;
		if (continuar==1){
			continue;
		}else if(continuar==2){
			break;
		}else{
			cout<<"Valor invalido"<<endl;
		}
	}while(true);
	return 0;
}
char* leer(){
	
}
void dibujo(int errores){
	if (errores==0){
		cout<<endl<<endl
	   <<"  	 +     "<<endl
	   <<"   	 |      "<<endl
	   <<"          "<<endl
	   <<"          "<<endl
	   <<"          "<<endl
	   <<"          "<<endl
	   <<"    ==========="<<endl<<endl;
	}else if(errores==1){
		cout<<endl<<endl
	   <<"  	 +  "<<endl
	   <<"   	 |      "<<endl
	   <<"   	 O      "<<endl
	   <<"   	 |      "<<endl
	   <<"           "<<endl
	   <<"           "<<endl
	   <<"    ==========="<<endl<<endl;
	}else if(errores==2){
		cout<<endl<<endl
	   <<"   	 +   "<<endl
	   <<"   	 |       "<<endl
	   <<"   	 O       "<<endl
	   <<"     	/|       "<<endl
	   <<"           "<<endl
	   <<"          "<<endl
	   <<"    ==========="<<endl<<endl;
	}else if(errores==3){
		cout<<endl<<endl
	   <<"   	 +  "<<endl
	   <<"  	 |      "<<endl
	   <<"  	 O      "<<endl
	   <<"  	/|\\      "<<endl
	   <<"           "<<endl
	   <<"           "<<endl
	   <<"    ==========="<<endl<<endl;
	}else if(errores==4){
		cout<<endl<<endl
	   <<"   	 +  "<<endl
	   <<"   	 |      "<<endl
	   <<"   	 O      "<<endl
	   <<"  	/|\\     "<<endl
	   <<"    	  \\      "<<endl
	   <<"          "<<endl
	   <<"    ==========="<<endl<<endl;
	}else if(errores==5){
		cout<<endl
		<<"     DERROTA!!! "<<endl
		<<"    	 +    "<<endl
		<<"   	 |        "<<endl
		<<"  	 O    	   "<<endl
		<<"  	/|\\       "<<endl
		<<"  	/ \\      "<<endl
		<<"            "<<endl
		<<"    ==========="<<endl<<endl;
	}
}

int juego(char* palabra){
	int falla=0;
	int expuesto=0;
	char mostrar[strlen(palabra)];
	char respuesta[strlen(palabra)];
	char incorrectas[strlen(palabra)];
	incorrectas[0]='\0';
	int verificar;
	strcpy(mostrar,palabra);
	for (int i = 0; i < strlen(palabra); i++){
		mostrar[i]='*';
	}
	while(expuesto<strlen(palabra)){
		
		dibujo(falla);
		if (falla==5){
			break;
		}
		cout<<"      ";
		for (int i = 0; i < strlen(mostrar); ++i){ 
			cout<<mostrar[i]<<" ";
		}
		cout<<endl;
		cout<<"Ingrese una letra o palabra: ";
		cin>>respuesta;
		if (strlen(respuesta)>1){
			cout<<"Si ingresa una palabra y está incorrecta, perderá el juego"<<endl
			    <<"Esta seguro de que quiere ingresar una palabra, en vez de una letra?"<<endl
			    <<"1. Si"<<endl
			    <<"2. No"<<endl;
			cin>>verificar;
			if (verificar==1){
				if (strcmp(palabra,respuesta)==0){
					return falla;
				}else{
					return 5;
				}
			}else if(verificar==2){
				continue;
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}
		bool correcto=false;
			
		
		for (int i = 0; i < strlen(incorrectas); ++i){
			if (*respuesta==incorrectas[i]){
				cout<<respuesta<<" ya a sido utilizado!"<<endl;
				cout<<"Usados: "<<incorrectas<<endl;
				correcto=true;
				break;
			}
		}

		for (int i = 0; i < strlen(palabra); i++){
			if (*respuesta==palabra[i]){
				if (mostrar[i]==palabra[i]){
					cout<<respuesta<<" ya a sido utilizado"<<endl;
					correcto=true;
					break;
				}else{
					mostrar[i]=palabra[i];
					expuesto++;
					cout<<"Usados: "<<incorrectas<<endl;
					correcto=true;
				}
			}
		}
		if (!correcto){
			strcat(incorrectas,respuesta);
			falla++;
			cout<<"Usados: "<<incorrectas<<endl;;
		}

	}
	return falla;
}