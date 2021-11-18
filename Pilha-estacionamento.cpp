/* Bernardo Murta Bastos – Questão 1
*/
#include <iostream>

using namespace std;

    class Noh {
        friend class Pilha;
        private:
            string dado; 
            Noh* proximo;
        public:
            Noh(string info){
                dado = info;
                proximo = NULL;
            }
            ~Noh(){
                proximo = NULL;
                delete proximo;
            }
    };

// pilha dinamicamente encadeada
    class Pilha {
    private:
        Noh* topo;
    
    public:
        Pilha();
        ~Pilha();
        void empilha(string info);
        string desempilha();
};


Pilha::Pilha() {
    topo = NULL;
}

Pilha::~Pilha() { 
    //limpaPilha();
    }


void Pilha::empilha(string info) {
    Noh* temporario = new Noh(info);
    temporario->proximo = topo;
    topo = temporario;    
}

string Pilha::desempilha() {
    Noh* temporario;
    string retorno;
    temporario = topo;
    if (temporario != NULL){
		topo = topo->proximo;
		temporario->proximo = NULL;
		retorno = temporario->dado;
		delete temporario;
		return retorno;
	}
	else 
		return "-1";
}


int main() 
{
    
    Pilha P1;
    Pilha P2;
    Pilha P3;
    Pilha P5;
    Pilha P6;
    Pilha P7;


    string elemento1;
    string Controle;
    string placa; 
    string pplaca;
    string a;
    int i = 0;
    int j=0;
    int cont2=0;
    int cont3=0;
    int cont4=0;
    int cont5=0;
   


    while (Controle != "e")
    {
        cout << "C - Entrada" << endl;
        cout << "S - Saida" << endl;
        cout << "M - Mostrar as placas apos entrada de carros"<<endl;
        cout << "e - Finalizar " << endl;
        cout<<endl;


        cout<<"Opcao:";
      cin >> Controle; 


   if(Controle=="C")
        {
          if(cont2<11){
            cout<<"Placa:"<<" ";
            cin >> placa; //Lista de numeros para insersao na fila
        P1.empilha( placa );
        i++;
        P3.empilha( placa );
        j++;
        cont2++;
        
        }
        
    while( cont3< i )
    {
        P2.empilha ( P1.desempilha() ); 
        cont3++;
    }
        }

    cout << endl;
    cout<<"Contem um total de " <<cont2<<" veiculos"<<endl<<endl;


    if(Controle=="M")
        {
    cout<<"Placas: ";
    cont4 = 0;
    while ( cont4 < cont2 )
    {
        cout << P2.desempilha() <<endl; 
        cont4++;
    }
    cout<<"Total de veiculos: "<<cont2;
  cout<<endl;
    }


  

  if(Controle=="S") {
      cout<<"insira a placa do carro: ";
      cin>>pplaca; 

string vet[j];

    for(int i=0;i<j;i++){
        vet[i]=(P3.desempilha());
        
    }
   
    for(int k=j;k>-1;k--){
        if(pplaca==vet[k]){
        P7.empilha(vet[k]);}
        else{
            P1.empilha(vet[k]);
            cont5++;
        }
    }    
    cout<<"Carros: "<<endl;
     while(cont5!=0){
        cout<<P1.desempilha()<<endl;
        cont5--;
} }
cout<<"Contem um total de"<<cont2<<" veiculos.";
    }
    return 0;
    
}