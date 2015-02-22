#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
void dibujo(int);
int juego(char*);
int menu();

int main(int argc, char const *argv[]){
	srand(time(0));
	int errores=0;
	int continuar,ran;
	char* w=new char[100];
	int op;
	char** array=new char*[100];
	do{
		op=menu();//dependiendo de la dificultad del juego se selecciona un archivo
		if (op==1){
			ifstream file("facil.txt");
			int cont=0;
			while (!file.eof()){
				file.getline(w,sizeof(file));//agarra la linea
				array[cont]=new char(strlen(w)+1);
				strcpy(array[cont],w);//copia la cadena al arreglo
				cont++;
			}
			file.close();
			ran=rand()%cont;
			strcpy(w,array[ran]);
		}else if(op==2){
			ifstream file("medio.txt");
			int cont=0;
			while (!file.eof()){
				file.getline(w,sizeof(file));
				array[cont]=new char(strlen(w)+1);
				strcpy(array[cont],w);
				cont++;
			}
			file.close();
			ran=rand()%cont;
			strcpy(w,array[ran]);
		}else if(op==3){
			ifstream file("dificil.txt");
			int cont=0;
			while (!file.eof()){
				file.getline(w,sizeof(file));
				array[cont]=new char(strlen(w)+1);
				strcpy(array[cont],w);
				cont++;
			}
			file.close();
			ran=rand()%cont;
			strcpy(w,array[ran]);
		}else{
			break;
		}
		
		errores=juego(w);
		if (errores==5){
			cout<<"Eres un loser! La palabra correcta era: "<<w<<endl<<endl<<endl;
		}else{
			cout<<"Eres un ganador! Adivinastes la palabra: "<<w<<"!!!!"<<endl<<endl<<endl;
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

int menu(){
	int resp;
	do{
		cout<<"\n\tMenu"<<endl
			<<"1. Jugar"<<endl
			<<"2. Salir"<<endl;
		cin>>resp;
		if (resp==1){
			cout<<"\nNiveles de dificultad"<<endl
				<<"1. Facil"<<endl
				<<"2. Medio"<<endl
				<<"3. Difcil"<<endl;
				cin>>resp;
				if (resp==1){
					return 1;
				}else if(resp==2){
					return 2;
				}else if(resp==3){
					return 3;
				}else{
					cout<<"Valor invalido!\n"<<endl;
				}
		}else if(resp==2){
			return 0;
		}else{
			cout<<"Ingrese un valor valido!"<<endl;
		}
	}while(true);
}

void dibujo(int errores){//dependiendo de los errores sale un output diferente
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
	bool correcto;
	char mostrar[strlen(palabra)];
	char respuesta[strlen(palabra)];
	char incorrectas[strlen(palabra)];
	incorrectas[0]='\0';
	int verificar;
	strcpy(mostrar,palabra);
	for (int i = 0; i < strlen(palabra); i++){//desde 0 hasta el tama;o de la palabra se le asigna *
		mostrar[i]='*';
	}
	while(expuesto<strlen(palabra)){
		
		dibujo(falla);
		if (falla==5){
			break;
		}
		cout<<"      ";
		for (int i = 0; i < strlen(mostrar); ++i){ //imprime la palabra a mostrar
			cout<<mostrar[i]<<" ";
		}
		cout<<endl;

		cout<<"Ingrese una letra o palabra: ";
		cin>>respuesta;
		if (strlen(respuesta)>1){//si la respuesta que se ingresa tiene mas de 1 caracter
			cout<<"\nSi ingresa una palabra y está incorrecta, perderá el juego"<<endl
			    <<"Esta seguro de que quiere ingresar una palabra, en vez de una letra?"<<endl
			    <<"1. Si"<<endl
			    <<"2. No"<<endl;
			cin>>verificar;
			if (verificar==1){
				if (strcmp(palabra,respuesta)==0){//compara la palabra secreta con la respuesta
					return falla;
				}else{
					return 5;//si no es la palabra correcta devuelve 5, pierde
				}
			}else if(verificar==2){//si ingresa 2, sigue el juego
				continue;
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}
		correcto=false;
			
		
		for (int i = 0; i < strlen(incorrectas); ++i){//verifica si ya uso una letra incorrecta
			if (*respuesta==incorrectas[i]){
				cout<<respuesta<<" ya a sido utilizado!"<<endl;
				correcto=true;
				break;
			}
		}

		for (int i = 0; i < strlen(palabra); i++){
			if (*respuesta==palabra[i]){//verifica si la letra esta en la palabra
				if (mostrar[i]==palabra[i]){//verifica si la palabra mostrada ya a sido utilizada
					cout<<respuesta<<" ya a sido utilizado"<<endl;
					correcto=true;
					break;
				}else{//si la letra es correcta, muestra esa letra
					mostrar[i]=palabra[i];
					expuesto++;
					correcto=true;
				}

			}
		}
		if (correcto){
			cout<<"Usados: "<<incorrectas<<endl;
		}
		if (!correcto){//si no esta correcto
			strcat(incorrectas,respuesta);//concatena a la cadena
			falla++;
			cout<<"Usados: "<<incorrectas<<endl;;
		}

	}
	return falla;
}