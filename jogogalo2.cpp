#include <stdio.h>

char tabuleiro [3][3];

void LimparTabuleiro(){
  int linha,coluna;
  for (linha=0; linha <3;linha=linha+1)
  for (coluna=0; coluna <3;coluna=coluna+1 )
   tabuleiro [linha][coluna]= ' ';

}

void MostrarTabuleiro(){
	int linha;
	for (linha=0;linha<3;linha=linha+1){
	printf("\n");
	printf(" %c | %c | %c\n",tabuleiro[linha][0],tabuleiro[linha][1],tabuleiro[linha][2]);
	
	if (linha <2 ){
	printf("---|---|---");
}
}
}

int PerguntarAlinhaDoProximoPeao() 
{
	int linha=0;
	printf("Qual a linha (0-2):");
	scanf ("%d",&linha);
	return linha;

}

int PerguntarAColunaDoProximoPeao() 
{
	int Coluna=0;
	printf(" Qual a Coluna (0-2): ");
	scanf ("\n%d",&Coluna);
	return Coluna;

}

void PorPeaoNoTabuleiro( char peao,int linha,int coluna){
	if (tabuleiro[linha][coluna]==' '){
	    tabuleiro[linha][coluna]=peao;}
		
	else{
	 printf("\n\nOcupado\n\n");}
}


int VerificarSeJogadaVencedora (char peao)
{
    int linha,coluna;
    for (linha=0;linha<3;linha++)
    {
    
    	
        if ((tabuleiro[linha][0]==peao)
        &&   (tabuleiro[linha][1]==peao)
        &&   (tabuleiro[linha][2]==peao ))
            {
            return 1;
            break;
            }
        
		}
        
        
        for (coluna=0;coluna<3;coluna++){
	
        
        
         if  ((tabuleiro[0][coluna]==peao) && 
		     (tabuleiro[1][coluna]==peao)&& 
		     (tabuleiro[2][coluna]==peao )){
            return 1;
            break;
            }
        }
        //diagonal principal
        if ((tabuleiro[0][0]==peao)&&
            (tabuleiro[1][1]==peao)&&
            (tabuleiro[2][2]==peao))
			{
			return 1;
			}
            
             //diagonal segundaria
		if ((tabuleiro[0][2]==peao)&&
            (tabuleiro[1][1]==peao)&&
            (tabuleiro[2][0]==peao))
			{
			return 1;
			}
	return 0;	
  }
  //Empate
  int TabuleiroCheio() {
    int linha, coluna;
    for (linha = 0; linha < 3; linha++)
        for (coluna = 0; coluna < 3; coluna++)
            if (tabuleiro[linha][coluna] == ' ')
                return 0; // Ainda há espaço
    return 1; // Tabuleiro cheio
}
       
int main ()
{
	LimparTabuleiro();
	while(1)
	{
	
		int linha,coluna=0;
		printf(" \nJogador O:");
		linha = PerguntarAlinhaDoProximoPeao();
		coluna = PerguntarAColunaDoProximoPeao(); 
		
		PorPeaoNoTabuleiro('O', linha, coluna);
		MostrarTabuleiro();	
		
		int ganhou=VerificarSeJogadaVencedora('O');
		if (ganhou==1)
			{
			printf("\nJogador  O ganhou !!!!");return 1;
			}
		
		printf(" \nJogador X: ");
		linha = PerguntarAlinhaDoProximoPeao();
		coluna = PerguntarAColunaDoProximoPeao(); 
		
		PorPeaoNoTabuleiro('X', linha, coluna);
		MostrarTabuleiro();	
		
		ganhou=VerificarSeJogadaVencedora('X');
		if (ganhou==1)
			{
			printf("\nJogador X ganhou !!!!");return 1;
			}
		
		int empate = TabuleiroCheio();
		  if (empate) {
          printf("Empate!\n");
           return 0;
}      

	}
return 0;
}
     
