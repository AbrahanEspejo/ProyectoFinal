#include<conio.h>
#include<iostream>
#include<string.h>
#define max 30

using namespace std;

/********************/

struct nodo{
	string nombre;
	string correo;
	string contrasena;
	string nacimiento;
	int edad;
	string sexo;
	struct nodo *sgte;
};

/***********************/

struct nodomsj{
	string mensaje;
	string autor;
	string destino;
	struct nodomsj *sgte;
};

/***********************/

struct nodopub{
	string mensaje;
	string autor;
	int likes=0;
	int dislikes=0;
	struct nodopub *sgte;
};

/***********************************************/

struct nodoami{
	string autor;
	string amigo;
	string nombre;
	string sexo;
	struct nodoami *sgte;
};

/***********************************************/

typedef struct nodo * datos;
typedef struct nodomsj * mensajes;
typedef struct nodopub * publi;
typedef struct nodoami * amigos;

/************************************/

void insertar(datos &,string,string,string,string,string,int);
void mostrar(datos);
bool iniciar(datos,string,string);
void enviarm(datos,mensajes &,string);
void vermsj(mensajes,string);
void pub(publi &,string);
void verpub(publi &);
void Perfil(datos ,string);
void amgs(amigos &,datos, string);
void veramgs(amigos ,string);

/***********************************************/
/***********************************************/

void veramgs(amigos amigo,string correo)
{
	bool aux=false;
	amigos a=amigo;
	while(a!=NULL)
	{
		if(a->autor.compare(correo)==0)
		{
			aux=true;
		}
		a=a->sgte;
	}
	if(aux==false)
	{
		cout<<"Esta cuenta no tiene ningun amigo agregado."<<endl;
	}
	if(aux==true)
	{
		cout<<"-----------------------"<<endl;
		cout<<"|        AMIGOS       |"<<endl;
		cout<<"-----------------------"<<endl<<endl;
		while(amigo!=NULL)
		{
			if(amigo->autor.compare(correo)==0)
			{
				cout<<"-----------------------"<<endl;
				cout<<"Nombre: "<<amigo->nombre<<endl;
				cout<<"Correo: "<<amigo->amigo<<endl;
			}
			amigo=amigo->sgte;
		}
		cout<<"-----------------------"<<endl;
	}
}


void amgs(amigos &amigo,datos perfil,string correo)
{
	cin.ignore();
	string correo1;
	amigos a=amigo;
	datos a1=perfil,b1=perfil,c1=perfil;
	while(a1!=NULL)
	{
		if(a1->correo.compare(correo)==1)
		{
			cout<<"\t#---------------------#"<<endl;
			cout<<"\t#       PERFILES      #"<<endl;
			cout<<"\t#---------------------#"<<endl;
			while(b1!=NULL)
			{
				if(b1->correo.compare(correo)!=0)
				{
					cout<<"\t#-----------------------"<<endl;
					cout<<"\tCorreo: "<<b1->correo<<endl;
					cout<<"\tNombre: "<<b1->nombre<<endl;
		   			cout<<"\tEdad: "<<b1->edad<<endl;
		   			cout<<"\tSexo: "<<b1->sexo<<endl;	
					cout<<"\t#-----------------------"<<endl;
				}
				b1=b1->sgte;
			}
			cout<<"-----------------------"<<endl;
			cout<<endl<<"\t Ingresa el correo del perfil a agregar: ";getline(cin,correo1);
			while(c1!=NULL)
			{
				if(c1->correo.compare(correo1)==0)
				{
					a=new(struct nodoami);
					a->autor=correo;
					a->amigo=c1->correo;
					a->nombre=c1->nombre;
					a->sexo=c1->sexo;
					a->sgte=amigo;
					amigo=a;
				}
			c1=c1->sgte;
			}
		}
		a1=a1->sgte;
	}
	cout<<"\t#==============================#"<<endl;
	cout<<"\t#==============================#"<<endl;
	cout<<"\t# Amigo agregado exitosamente. #"<<endl;
}

void Perfil(datos perfil,string correo)
{
	while(perfil!=NULL)
	{
		if(perfil->correo.compare(correo)==0)
		{
			system("cls");
			cout<<"\t\tPERFIL"<<endl;
			cout << "\t      _______      " << endl;
    		cout << "\t     /       \\    " << endl;
    		cout << "\t    |  O   O  |   " << endl;
   			cout << "\t    |    ^    |   " << endl;
    		cout << "\t    |   '-'   |   " << endl;
  			cout << "\t    \\         /   " << endl;
    		cout << "\t     \\_______/    " << endl<<endl;
    		cout<<"\tNombre: "<<perfil->nombre<<endl;
    		cout<<"\tEdad: "<<perfil->edad<<endl;
    		cout<<"\tSexo: "<<perfil->sexo<<endl;
    		cout<<"\tFecha de Nacimiento: "<<perfil->nacimiento<<endl;
		}
		perfil=perfil->sgte;
	}
}


void verpub(publi & p)
{
	char r;
	int op;
	publi q=p;
	if(p==NULL)
	{
		cout<<"\t#====================================#"<<endl;
		cout<<"\t# Aun no se creo ninguna publicaion: #"<<endl;
		cout<<"\t#====================================#"<<endl;
	}else
	{
		while(q!=NULL)
		{
			cout<<"\t*----------------------------------------------*"<<endl;
			cout<<"\tContenido: "<<q->mensaje<<endl;
			cout<<"\tAutor:"<<q->autor<<endl;
			cout<<"\t"<<q->likes<<"    "<<q->dislikes<<endl;
			cout<<"\t*----------------------------------------------*"<<endl;
			cout<<"\tDesea reaccionar a la publicacion?(s/n): ";cin>>r;
			if(r=='s')
			{
				cout<<"\t1.-Like"<<endl<<"\t2.-Dislike"<<endl<<"\tIngrese una opcion: ";cin>>op;
				if(op==1)
				{
					cout<<"\t#====================================#"<<endl;
					cout<<"\t# Le dio -me gusta- a la publicaion. #"<<endl;
					cout<<"\t#====================================#"<<endl;
					q->likes++;
				}
				if(op==2)
				{
					cout<<"\t#=======================================#"<<endl;
					cout<<"\t# Le dio -no me gusta- a la publicaion. #"<<endl;
					cout<<"\t#=======================================#"<<endl;
					q->dislikes++;
				}
			}
			q=q->sgte;
		}
	}
	getch();
	
}

void pub(publi & p,string correo)
{
	publi q;
	string pbl;
	cin.ignore();
	cout<<"\tIngrese la publicacion: ";getline(cin,pbl);
	q=new(struct nodopub);
	q->autor=correo;
	q->mensaje=pbl;
	q->sgte=p;
	p=q;
}

void vermsj(mensajes mensaje,string correo)
{
	mensajes p=mensaje,q=mensaje;
	if(mensaje==NULL)
	{
		cout<<"\t#===========================================#"<<endl;
		cout<<"\t# ---AUN NO SE HA ENVIADO NINGUN MENSAJE--- #"<<endl;
		cout<<"\t#===========================================#"<<endl;
	}else{
		cout<<"\t#===========================================#"<<endl;
		cout<<"\t#        -----MENSAJES ENVIADOS:-----       #"<<endl;
		cout<<"\t#===========================================#"<<endl;
		while(p!=NULL)
		{
			if(p->autor==correo)
			{
				cout<<"\t***********************************************"<<endl;
				cout<<"\tMensaje: "<<endl<<p->mensaje<<endl;
				cout<<"\tDestinatario: "<<p->destino<<endl;
				cout<<"\t***********************************************"<<endl;
			}
			p=p->sgte;
		}
	}
	if(mensaje==NULL)
	{
		cout<<"\t#============================================#"<<endl;
		cout<<"\t# ---AUN NO SE HA RECIBIDO NINGUN MENSAJE--- #"<<endl;
		cout<<"\t#============================================#"<<endl;
	}
	else{
		cout<<"\t#============================================#"<<endl;
		cout<<"\t#        -----MENSAJES RECIVIDOS:-----       #"<<endl;
		cout<<"\t#============================================#"<<endl;
		cout<<endl;										
		while(q!=NULL)
		{
			if(q->destino==correo)
			{
				cout<<"\t***********************************************"<<endl;
				cout<<"\tMensaje: "<<endl<<q->mensaje<<endl;
				cout<<"\tDe: "<<q->autor<<endl;
				cout<<"\t***********************************************"<<endl;
			}
			q=q->sgte;
		}
	}
}

void enviarm(datos perfil,mensajes &mensaje,string correo)
{
	datos p=perfil;
	mensajes q,m,r=mensaje;
	string autor,destino;
	string msj;
	cin.ignore();
	cout<<"\tIngrese el destinatario: ";
	getline(cin,destino);
	cout<<"\tIngrese el mensaje a enviar: ";
	getline(cin,msj);
	while(p!=NULL)
	{
		if(p->correo.compare(correo)==0)
		{
			q=new(struct nodomsj);
			q->autor=correo;
			q->destino=destino;
			q->mensaje=msj;
			q->sgte=NULL;
			if(mensaje==NULL) mensaje=q;
			else{
				m=mensaje;
				while(m->sgte!=NULL)m=m->sgte;
				m->sgte=q;
			}
		}
		p=p->sgte;
	}
	while(r!=NULL)
	{
		cout<<r->autor<<endl;
		cout<<r->mensaje<<endl;
		cout<<r->destino<<endl;
		r=r->sgte;
	}
}

bool iniciar(datos perfil,string correo,string contrasena)
{
	bool aux=false;
	while(perfil!=NULL)
	{
		if(perfil->correo.compare(correo)==0 && perfil->contrasena.compare(contrasena)==0)
		{
			return true;
		}
		perfil=perfil->sgte;
	}
	return false;
}

void insertar(datos &perfil,string nombre,string correo,string contrasena,string nacimiento,string sexo,int edad)
{
	datos q=new(struct nodo);
	datos p=perfil;
	bool aux1=true;
	while(p!=NULL){
		if(p->correo.compare(correo)==0 || p->contrasena.compare(contrasena)==0){
			aux1=false;
		}
		p=p->sgte;
	}
	if(aux1==true)
	{
		q->nombre=nombre;
		q->correo=correo;
		q->contrasena=contrasena;
		q->nacimiento=nacimiento;
		q->sexo=sexo;
		q->edad=edad;
		q->sgte=perfil;
		perfil=q;
	}
	if(aux1==true)
	{
		cout<<"\t****************************************"<<endl;
		cout<<"\t* Su cuenta a sido creada exitosamente *"<<endl;
		cout<<"\t****************************************"<<endl;
	}
	if(aux1==false)
	{
		cout<<"\t#===========================================================#"<<endl;
		cout<<"\t# Uno o mas datos ingresados ya se encuentran registrados!! #"<<endl;
		cout<<"\t#===========================================================#"<<endl;
	}
		getch();
}

void mostrar(datos perfil)
{

	cout<<"\tNombre: "<<perfil->nombre<<endl;
	cout<<"\tCorreo: "<<perfil->correo<<endl;
	cout<<"\tContrasenia: "<<perfil->contrasena<<endl;
	cout<<"\tEdad: "<<perfil->edad<<endl;
	cout<<"\tFecha de nacimiento: "<<perfil->nacimiento<<endl;
	cout<<"\tSexo: "<<perfil->sexo<<endl;
	
}


int main()
{
	publi publicar=NULL;
	datos perfil=NULL;
	mensajes mensaje=NULL;
	amigos amigo=NULL;
	int op1,op2,op3,edad,aux1=0;
	string nombre;
	string correo;
	string contrasena;
	string nacimiento;
	string sexo;
	string correo1;
	string contrasena1;
	char volver,volver1,volver2;
	do{
		system("cls");
		cout<<"\t************************************"<<endl;
		cout<<"\t***********  UNUVIRTUAL  ***********"<<endl;
		cout<<"\t************************************"<<endl;
		cout<<endl;
		cout<<"\t#==================================#"<<endl;
		cout<<"\t# 1.-INICIAR SESION.               #"<<endl;
		cout<<"\t# 2.-CREAR CUENTA.                 #"<<endl;
		cout<<"\t# 3.-SALIR.                        #"<<endl;
		cout<<"\t#==================================#"<<endl;
		cout<<endl<<"Ingrese una opcion: ";cin>>op1;
		system("cls");
		switch (op1)
		{
			case 1:		if(perfil==NULL)
						{
							cout<<"\t#===============================================================#"<<endl;
							cout<<"\t# El registro de cuentas esta vacio, por favor cree una cuenta. #"<<endl;
							cout<<"\t#===============================================================#"<<endl;
							volver='s';
							getch();
						}else{
							cout<<"\t#=========================#"<<endl;
							cout<<"\t#     INICIAR SESION      #"<<endl;
							cout<<"\t#=========================#"<<endl;
							cout<<"\tIngrese su correo: ";cin>>correo1;
							cout<<"\tIngrese su contrasena: ";cin>>contrasena1;
							cout<<endl;
							if(iniciar(perfil,correo1,contrasena1)==true)
							{
								system("cls");
								cout<<"\t\t#=========================#"<<endl;
								cout<<"\t\t#  -----BIENVENIDO-----   #"<<endl;
								cout<<"\t\t#=========================#"<<endl<<endl;
								getch();
								do{
									system("cls");
									cout<<"\t\t***********************************"<<endl;
									cout<<"\t\t*            UNUVIRTUAL           *"<<endl;
									cout<<"\t\t***********************************"<<endl;
									cout<<"\t#========================================================#"<<endl;
									cout<<"\t# 1.INICIO | 2.PERFIL | 3.MENSAJES  | 4.AMIGOS | 5.SALIR #"<<endl,
									cout<<"\t#========================================================#"<<endl;
									cout<<endl<<"\tINGRESE UNA OPCION: ";cin>>op2;
									switch (op2)
									{
										case 1: system("cls");
												cout<<"\t#=======================#"<<endl;
												cout<<"\t# 1.-Publicar.          #"<<endl;
												cout<<"\t# 2.-Ver Publicaciones. #"<<endl;
												cout<<"\t#=======================#"<<endl;
												cout<<"\tIngrese una opcion: ";cin>>op3;
												switch (op3)
												{
													case 1: pub(publicar,correo1);
															cout<<"\t#==========================#"<<endl;
															cout<<"\t# Se publico corectamente. #"<<endl;
															cout<<"\t#==========================#"<<endl;
															cout<<endl<<"\tVolver al menu?(s/n): ";cin>>volver1;
															break;
													
													case 2: verpub(publicar);
															cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
															break;
												}
												break;
												
										case 2: Perfil(perfil,correo1);
												cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
												break;
										
										case 3:	system("cls");
												cout<<"\t#====================#"<<endl;
												cout<<"\t# 1.-enviar mensaje. #"<<endl;
												cout<<"\t# 2.-ver mensajes.   #"<<endl;
												cout<<"\t#====================#"<<endl;
												cout<<"\tingrese una opcion: ";cin>>op3;
												switch (op3)
												{
													case 1: cout<<endl;
															enviarm(perfil,mensaje,correo1);
															cout<<"\t#=====================#"<<endl;
															cout<<"\t$ --correo enviado--  #"<<endl;
															cout<<"\t#=====================#"<<endl;
															cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
															break;
															
													case 2: vermsj(mensaje,correo1);
															cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
															break;			
												}
												break;
										case 4: system("cls");
												cout<<"\t#======================#"<<endl;
												cout<<"\t#  1.-Ver amigos.      #"<<endl;
												cout<<"\t#  2.-Agregar amigos.  #"<<endl;
												cout<<"\t#======================#"<<endl;
												cout<<"Ingrese una opcion: ";cin>>op3;
												if(op3==1)
												{
													veramgs(amigo,correo1);
													cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
													break;
												}
												if(op3==2)
												{
													amgs(amigo,perfil,correo1);
													cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver1;
													break;
												}
												break;
									}	
								}while(volver1=='s' && op2!=5);
							//	getch();
							}
							if(iniciar(perfil,correo1,contrasena1)==false)
							{
								system("cls");
								cout<<"\t#================================#"<<endl;
								cout<<"\t# Correo o contrasena incorrecta #"<<endl;
								cout<<"\t#================================#"<<endl;
								cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver;
							}
						}
						break;
			case 2: cin.ignore();
					cout<<"\tingrese su nombre: ";
					getline(cin,nombre);
					cout<<"\tingrese su correo: ";
					getline(cin,correo);
					cout<<"\tingrese su contrasena: ";
					getline(cin,contrasena);
					cout<<"\tingrese su fecha de nacimiento: ";
					getline(cin,nacimiento);
					cout<<"\tingrese su edad: ";
					cin>>edad;
					cin.ignore();
					cout<<"\tingrese su sexo: ";
					getline(cin,sexo);
					system("cls");
					insertar(perfil,nombre,correo,contrasena,nacimiento,sexo,edad);
					mostrar(perfil);
					cout<<endl<<"\tVolver al menu(s/n): ";cin>>volver;
					break;
		}
			
	}while(op1!=3 && volver=='s');
	
	return 0;
}