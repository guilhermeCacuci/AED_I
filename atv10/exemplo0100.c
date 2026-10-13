/*
   Exemplo1010 - v0.1. - 13 / 10 / 2026
   Author: Guilherme Caçuci Ladislau - Matricula: 851609
*/

// dependencias
#include "io.h" // para definicoes proprias

// ----------------------------------------------- definicoes globais (Arranjos)

/**
   Definicao de tipo arranjo com inteiros baseado em estrutura
*/
typedef
struct s_int_Array
{
   int  length;
   ints data  ;
   int  ix    ;
}
int_Array;

/**
   Definicao de referencia para arranjo com inteiros baseado em estrutura
*/
typedef int_Array* ref_int_Array;

/**
   new_int_Array - Reservar espaco para arranjo com inteiros
   @return referencia para arranjo com inteiros
   @param n - quantidade de dados
*/
ref_int_Array new_int_Array ( int n )
{
   ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));
   if ( tmpArray == NULL )
   {
      IO_printf ( "\nERRO: Falta espaco.\n" );
   }
   else
   {
      tmpArray->length = 0;
      tmpArray->data   = NULL;
      tmpArray->ix     = -1;
      if ( n > 0 )
      {
         tmpArray->length = n;
         tmpArray->data   = (ints) malloc (n * sizeof(int));
         tmpArray->ix     = 0;
      } // end if
   } // end if
   return ( tmpArray );
} // end new_int_Array ( )

/**
   free_int_Array - Dispensar espaco para arranjo com inteiros
   @param tmpArray - referencia para grupo de valores inteiros
*/
void free_int_Array ( ref_int_Array tmpArray )
{
   if ( tmpArray != NULL )
   {
      if ( tmpArray->data != NULL )
      {
         free ( tmpArray->data );
      } // end if
      free ( tmpArray );
   } // end if
} // end free_int_Array ( )

/**
   printIntArray - Mostrar arranjo com valores inteiros.
   @param array - referencia para grupo de valores inteiros
*/
void printIntArray ( ref_int_Array array )
{
   if ( array != NULL && array->data != NULL )
   {
      for ( array->ix = 0; array->ix < array->length; array->ix = array->ix + 1 )
      {
         printf ( "%2d: %d\n", array->ix, array->data [ array->ix ] );
      } // end for
   } // end if
} // end printIntArray ( )

/**
   fprintIntArray - Gravar arranjo com valores inteiros em arquivo.
   @param fileName - nome do arquivo
   @param array - referencia para grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, ref_int_Array array )
{
   FILE* arquivo = fopen ( fileName, "wt" );
   if ( arquivo == NULL )
   {
      IO_printf ( "\nERRO: Nao foi possivel abrir o arquivo.\n" );
   }
   else
   {
      if ( array != NULL && array->data != NULL && array->length > 0 )
      {
         fprintf ( arquivo, "%d\n", array->length );
         for ( array->ix = 0; array->ix < array->length; array->ix = array->ix + 1 )
         {
            fprintf ( arquivo, "%d\n", array->data [ array->ix ] );
         } // end for
      } // end if
      fclose ( arquivo );
   } // end if
} // end fprintIntArray ( )

/**
   readArrayFromFile - Ler arranjo com valores inteiros de arquivo.
   @return referencia para arranjo com os valores lidos
   @param fileName - nome do arquivo
*/
ref_int_Array readArrayFromFile ( chars fileName )
{
   FILE* arquivo = fopen ( fileName, "rt" );
   ref_int_Array array = NULL;
   int n = 0;

   if ( arquivo == NULL )
   {
      IO_printf ( "\nERRO: Arquivo (%s) nao encontrado.\n", fileName );
   }
   else
   {
      fscanf ( arquivo, "%d", &n );
      if ( n <= 0 )
      {
         IO_printf ( "\nERRO: Tamanho de arranjo invalido.\n" );
      }
      else
      {
         array = new_int_Array ( n );
         if ( array != NULL && array->data != NULL )
         {
            array->ix = 0;
            while ( ! feof ( arquivo ) && array->ix < array->length )
            {
               fscanf ( arquivo, "%d", &(array->data [ array->ix ]) );
               array->ix = array->ix + 1;
            } // end while
         } // end if
      } // end if
      fclose ( arquivo );
   } // end if
   return ( array );
} // end readArrayFromFile ( )

// ----------------------------------------------- definicoes globais (Matrizes)

/**
   Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef
struct s_int_Matrix
{
   int   rows   ;
   int   columns;
   ints* data   ;
   int   ix, iy ;
}
int_Matrix;

/**
   Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix* ref_int_Matrix;

/**
   new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
   @return referencia para matriz de inteiros
   @param rows - quantidade de linhas
   @param columns - quantidade de colunas
*/
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
   ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
   if ( tmpMatrix != NULL )
   {
      tmpMatrix->rows    = 0;
      tmpMatrix->columns = 0;
      tmpMatrix->data    = NULL;
      if ( rows > 0 && columns > 0 )
      {
         tmpMatrix->rows    = rows;
         tmpMatrix->columns = columns;
         tmpMatrix->data    = (ints*) malloc (rows * sizeof(ints));
         if ( tmpMatrix->data )
         {
            for ( tmpMatrix->ix = 0;
                  tmpMatrix->ix < tmpMatrix->rows;
                  tmpMatrix->ix = tmpMatrix->ix + 1 )
            {
               tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
            } // end for
         } // end if
      } // end if
      tmpMatrix->ix = 0;
      tmpMatrix->iy = 0;
   } // end if
   return ( tmpMatrix );
} // end new_int_Matrix ( )

/**
   free_int_Matrix - Dispensar espaco para matriz de inteiros
   @param matrix - referencia para matriz de inteiros
*/
void free_int_Matrix ( ref_int_Matrix matrix )
{
   if ( matrix != NULL )
   {
      if ( matrix->data != NULL )
      {
         for ( matrix->ix = 0;
               matrix->ix < matrix->rows;
               matrix->ix = matrix->ix + 1 )
         {
            free ( matrix->data [ matrix->ix ] );
         } // end for
         free ( matrix->data );
      } // end if
      free ( matrix );
   } // end if
} // end free_int_Matrix ( )

/**
   printIntMatrix - Mostrar matriz com valores inteiros.
   @param matrix - referencia para matriz de inteiros
*/
void printIntMatrix ( ref_int_Matrix matrix )
{
   if ( matrix != NULL && matrix->data != NULL )
   {
      for ( matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1 )
      {
         for ( matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1 )
         {
            printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
         } // end for
         printf ( "\n" );
      } // end for
   } // end if
} // end printIntMatrix ( )

/**
   fprintIntMatrix - Gravar matriz com valores inteiros em arquivo.
   @param fileName - nome do arquivo
   @param matrix - referencia para matriz de inteiros
*/
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix )
{
   FILE* arquivo = fopen ( fileName, "wt" );
   if ( matrix == NULL || arquivo == NULL )
   {
      IO_printf ( "\nERRO: Nao ha' dados ou arquivo invalido.\n" );
   }
   else
   {
      fprintf ( arquivo, "%d\n", matrix->rows );
      fprintf ( arquivo, "%d\n", matrix->columns );
      if ( matrix->data != NULL )
      {
         for ( matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1 )
         {
            for ( matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1 )
            {
               fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
            } // end for
         } // end for
      } // end if
      fclose ( arquivo );
   } // end if
} // end fprintIntMatrix ( )

/**
   readMatrixFromFile - Ler matriz com valores inteiros de arquivo.
   @return referencia para matriz lida
   @param fileName - nome do arquivo
*/
ref_int_Matrix readMatrixFromFile ( chars fileName )
{
   ref_int_Matrix matrix = NULL;
   int   rows    = 0;
   int   columns = 0;
   FILE* arquivo = fopen ( fileName, "rt" );

   if ( arquivo == NULL )
   {
      IO_printf ( "\nERRO: Arquivo (%s) nao encontrado.\n", fileName );
   }
   else
   {
      fscanf ( arquivo, "%d", &rows );
      fscanf ( arquivo, "%d", &columns );
      if ( rows <= 0 || columns <= 0 )
      {
         IO_printf ( "\nERRO: Dimensoes invalidas.\n" );
      }
      else
      {
         matrix = new_int_Matrix ( rows, columns );
         if ( matrix != NULL && matrix->data != NULL )
         {
            matrix->ix = 0;
            while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
            {
               matrix->iy = 0;
               while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
               {
                  fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
                  matrix->iy = matrix->iy + 1;
               } // end while
               matrix->ix = matrix->ix + 1;
            } // end while
            matrix->ix = 0;
            matrix->iy = 0;
         } // end if
      } // end if
      fclose ( arquivo );
   } // end if
   return ( matrix );
} // end readMatrixFromFile ( )

// ----------------------------------------------- funcoes dos exercicios

/**
   RandomIntGenerate - Gerar valor inteiro aleatorio dentro de um intervalo.
   @return valor aleatorio gerado
   @param inferior - limite inferior
   @param superior - limite superior
*/
int RandomIntGenerate ( int inferior, int superior )
{
   int valor = 0;
   int limite = 1000000; // 10^6
   if ( inferior <= superior )
   {
      valor = inferior + ( rand ( ) % ( ( superior - inferior + 1 ) <= limite ? ( superior - inferior + 1 ) : limite ) );
   } // end if
   return ( valor );
} // end RandomIntGenerate ( )

/**
   Method_11 (1011) - Gerar N valores aleatorios no intervalo [inferior, superior]
   e gravar em "DADOS.TXT".
*/
void method_11 ( void )
{
// definir dados
   int inferior = 0;
   int superior = 0;
   int n        = 0;
   ref_int_Array arranjo = NULL;

// identificar
   IO_id ( "Method_11 (1011) - v0.0" );

// ler limites e quantidade
   inferior = IO_readint ( "Entrar com o limite inferior: " );
   superior = IO_readint ( "Entrar com o limite superior: " );
   n        = IO_readint ( "Entrar com a quantidade (N) : " );

// testar validade dos dados
   if ( inferior > superior || n <= 0 )
   {
      IO_printf ( "\nERRO: Intervalo ou quantidade invalidos.\n" );
   }
   else
   {
      arranjo = new_int_Array ( n );
      if ( arranjo != NULL && arranjo->data != NULL )
      {
         srand ( time ( NULL ) );
         for ( arranjo->ix = 0; arranjo->ix < arranjo->length; arranjo->ix = arranjo->ix + 1 )
         {
            arranjo->data [ arranjo->ix ] = RandomIntGenerate ( inferior, superior );
         } // end for

         IO_printf ( "\nValores gerados:\n" );
         printIntArray ( arranjo );
         fprintIntArray ( "DADOS.TXT", arranjo );
         IO_printf ( "\nDados gravados em DADOS.TXT com sucesso.\n" );

         free_int_Array ( arranjo );
      } // end if
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_11 ( )

/**
   arraySearch - Procurar certo valor inteiro em um arranjo.
   @return true se encontrar, false caso contrario
   @param valor - valor procurado
   @param arranjo - referencia para o arranjo
*/
bool arraySearch ( int valor, ref_int_Array arranjo )
{
   bool resposta = false;
   if ( arranjo == NULL || arranjo->data == NULL || arranjo->length <= 0 )
   {
      IO_printf ( "\nERRO: Arranjo vazio ou invalido.\n" );
   }
   else
   {
      arranjo->ix = 0;
      while ( arranjo->ix < arranjo->length && ! resposta )
      {
         if ( arranjo->data [ arranjo->ix ] == valor )
         {
            resposta = true;
         } // end if
         arranjo->ix = arranjo->ix + 1;
      } // end while
   } // end if
   return ( resposta );
} // end arraySearch ( )

/**
   Method_12 (1012) - Procurar valor em arranjo lido de arquivo.
*/
void method_12 ( void )
{
// definir dados
   ref_int_Array arranjo = NULL;
   int  valor    = 0;
   bool resposta = false;

// identificar
   IO_id ( "Method_12 (1012) - v0.0" );

// ler arranjo do arquivo
   arranjo = readArrayFromFile ( "DADOS.TXT" );
   if ( arranjo == NULL || arranjo->data == NULL )
   {
      IO_printf ( "\nERRO: Nao foi possivel carregar DADOS.TXT.\n" );
   }
   else
   {
      IO_printf ( "\nArranjo lido de DADOS.TXT:\n" );
      printIntArray ( arranjo );

      valor    = IO_readint ( "\nEntrar com o valor a procurar: " );
      resposta = arraySearch ( valor, arranjo );

      if ( resposta )
      {
         IO_printf ( "\nResultado: O valor (%d) FOI encontrado no arranjo.\n", valor );
      }
      else
      {
         IO_printf ( "\nResultado: O valor (%d) NAO foi encontrado no arranjo.\n", valor );
      } // end if

      free_int_Array ( arranjo );
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_12 ( )

/**
   arrayCompare - Comparar dois arranjos.
   @return true se forem iguais, false caso contrario
   @param arranjo1 - primeiro arranjo
   @param arranjo2 - segundo arranjo
*/
bool arrayCompare ( ref_int_Array arranjo1, ref_int_Array arranjo2 )
{
   bool resposta = false;
   if ( arranjo1 == NULL || arranjo1->data == NULL ||
        arranjo2 == NULL || arranjo2->data == NULL )
   {
      IO_printf ( "\nERRO: Dados ausentes.\n" );
   }
   else
   {
      if ( arranjo1->length != arranjo2->length )
      {
         IO_printf ( "\nAviso: Tamanhos incompativeis (%d != %d).\n", arranjo1->length, arranjo2->length );
         resposta = false;
      }
      else
      {
         resposta = true;
         arranjo1->ix = 0;
         while ( arranjo1->ix < arranjo1->length && resposta )
         {
            if ( arranjo1->data [ arranjo1->ix ] != arranjo2->data [ arranjo1->ix ] )
            {
               resposta = false;
            } // end if
            arranjo1->ix = arranjo1->ix + 1;
         } // end while
      } // end if
   } // end if
   return ( resposta );
} // end arrayCompare ( )

/**
   Method_13 (1013) - Comparar dois arranjos lidos de arquivos.
*/
void method_13 ( void )
{
// definir dados
   ref_int_Array arranjo1 = NULL;
   ref_int_Array arranjo2 = NULL;
   bool resposta = false;

// identificar
   IO_id ( "Method_13 (1013) - v0.0" );

// ler dados
   arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
   arranjo2 = readArrayFromFile ( "DADOS2.TXT" );

   if ( arranjo1 != NULL && arranjo2 != NULL )
   {
      IO_printf ( "\nArranjo 1 (DADOS1.TXT):\n" );
      printIntArray ( arranjo1 );
      IO_printf ( "\nArranjo 2 (DADOS2.TXT):\n" );
      printIntArray ( arranjo2 );

      resposta = arrayCompare ( arranjo1, arranjo2 );
      if ( resposta )
      {
         IO_printf ( "\nResultado: Os arranjos sao IGUAIS.\n" );
      }
      else
      {
         IO_printf ( "\nResultado: Os arranjos sao DIFERENTES.\n" );
      } // end if
   } // end if

// reciclar espaco
   free_int_Array ( arranjo1 );
   free_int_Array ( arranjo2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_13 ( )

/**
   arrayAdd - Somar dois arranjos, com o segundo multiplicado por constante.
   @return referencia para o arranjo resultante da soma
   @param arranjo1 - primeiro arranjo
   @param k - constante multiplicadora
   @param arranjo2 - segundo arranjo
*/
ref_int_Array arrayAdd ( ref_int_Array arranjo1, int k, ref_int_Array arranjo2 )
{
   ref_int_Array soma = NULL;
   if ( arranjo1 == NULL || arranjo1->data == NULL ||
        arranjo2 == NULL || arranjo2->data == NULL )
   {
      IO_printf ( "\nERRO: Dados ausentes.\n" );
   }
   else
   {
      if ( arranjo1->length != arranjo2->length || arranjo1->length <= 0 )
      {
         IO_printf ( "\nERRO: Tamanhos incompativeis.\n" );
      }
      else
      {
         soma = new_int_Array ( arranjo1->length );
         if ( soma != NULL && soma->data != NULL )
         {
            for ( soma->ix = 0; soma->ix < soma->length; soma->ix = soma->ix + 1 )
            {
               soma->data [ soma->ix ] = arranjo1->data [ soma->ix ] + ( k * arranjo2->data [ soma->ix ] );
            } // end for
         } // end if
      } // end if
   } // end if
   return ( soma );
} // end arrayAdd ( )

/**
   Method_14 (1014) - Somar arranjo1 + (-2 * arranjo2).
*/
void method_14 ( void )
{
// definir dados
   ref_int_Array arranjo1 = NULL;
   ref_int_Array arranjo2 = NULL;
   ref_int_Array soma     = NULL;

// identificar
   IO_id ( "Method_14 (1014) - v0.0" );

// ler dados
   arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
   arranjo2 = readArrayFromFile ( "DADOS2.TXT" );

   if ( arranjo1 != NULL && arranjo2 != NULL )
   {
      soma = arrayAdd ( arranjo1, -2, arranjo2 );
      if ( soma != NULL )
      {
         IO_printf ( "\nArranjo 1:\n" );
         printIntArray ( arranjo1 );
         IO_printf ( "\nArranjo 2:\n" );
         printIntArray ( arranjo2 );
         IO_printf ( "\nSoma (Arranjo1 + (-2) * Arranjo2):\n" );
         printIntArray ( soma );
         free_int_Array ( soma );
      } // end if
   } // end if

// reciclar espaco
   free_int_Array ( arranjo1 );
   free_int_Array ( arranjo2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_14 ( )

/**
   isArrayDecrescent - Dizer se um arranjo esta' em ordem decrescente.
   @return true se estiver em ordem decrescente, false caso contrario
   @param arranjo - referencia para o arranjo
*/
bool isArrayDecrescent ( ref_int_Array arranjo )
{
   bool resposta = true;
   if ( arranjo == NULL || arranjo->data == NULL || arranjo->length <= 0 )
   {
      IO_printf ( "\nERRO: Arranjo invalido.\n" );
      resposta = false;
   }
   else
   {
      arranjo->ix = 0;
      while ( arranjo->ix < ( arranjo->length - 1 ) && resposta )
      {
         if ( arranjo->data [ arranjo->ix ] < arranjo->data [ arranjo->ix + 1 ] )
         {
            resposta = false;
         } // end if
         arranjo->ix = arranjo->ix + 1;
      } // end while
   } // end if
   return ( resposta );
} // end isArrayDecrescent ( )

/**
   Method_15 (1015) - Testar se arranjo lido de arquivo e' decrescente.
*/
void method_15 ( void )
{
// definir dados
   ref_int_Array arranjo1 = NULL;
   bool resposta = false;

// identificar
   IO_id ( "Method_15 (1015) - v0.0" );

// ler dados
   arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
   if ( arranjo1 != NULL )
   {
      IO_printf ( "\nArranjo (DADOS1.TXT):\n" );
      printIntArray ( arranjo1 );

      resposta = isArrayDecrescent ( arranjo1 );
      if ( resposta )
      {
         IO_printf ( "\nResultado: O arranjo ESTA em ordem decrescente.\n" );
      }
      else
      {
         IO_printf ( "\nResultado: O arranjo NAO esta em ordem decrescente.\n" );
      } // end if

      free_int_Array ( arranjo1 );
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_15 ( )

/**
   matrixTranspose - Obter a transposta de uma matriz.
   @return referencia para a matriz transposta
   @param matriz1 - referencia para a matriz original
*/
ref_int_Matrix matrixTranspose ( ref_int_Matrix matriz1 )
{
   ref_int_Matrix matriz2 = NULL;
   if ( matriz1 == NULL || matriz1->data == NULL || matriz1->rows <= 0 || matriz1->columns <= 0 )
   {
      IO_printf ( "\nERRO: Matriz invalida.\n" );
   }
   else
   {
      matriz2 = new_int_Matrix ( matriz1->columns, matriz1->rows );
      if ( matriz2 != NULL && matriz2->data != NULL )
      {
         for ( matriz1->ix = 0; matriz1->ix < matriz1->rows; matriz1->ix = matriz1->ix + 1 )
         {
            for ( matriz1->iy = 0; matriz1->iy < matriz1->columns; matriz1->iy = matriz1->iy + 1 )
            {
               matriz2->data [ matriz1->iy ][ matriz1->ix ] = matriz1->data [ matriz1->ix ][ matriz1->iy ];
            } // end for
         } // end for
      } // end if
   } // end if
   return ( matriz2 );
} // end matrixTranspose ( )

/**
   Method_16 (1016) - Obter a transposta de uma matriz lida de arquivo.
*/
void method_16 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   ref_int_Matrix matriz2 = NULL;

// identificar
   IO_id ( "Method_16 (1016) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   if ( matriz1 != NULL )
   {
      matriz2 = matrixTranspose ( matriz1 );
      IO_printf ( "\nMatriz Original (MATRIZ1.TXT):\n" );
      printIntMatrix ( matriz1 );
      IO_printf ( "\nMatriz Transposta:\n" );
      printIntMatrix ( matriz2 );

      free_int_Matrix ( matriz1 );
      free_int_Matrix ( matriz2 );
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_16 ( )

/**
   matrixZero - Testar se uma matriz so' contem valores iguais a zero.
   @return true se todos forem zero, false caso contrario
   @param matriz1 - referencia para a matriz
*/
bool matrixZero ( ref_int_Matrix matriz1 )
{
   bool resposta = true;
   if ( matriz1 == NULL || matriz1->data == NULL || matriz1->rows <= 0 || matriz1->columns <= 0 )
   {
      IO_printf ( "\nERRO: Matriz invalida.\n" );
      resposta = false;
   }
   else
   {
      matriz1->ix = 0;
      while ( matriz1->ix < matriz1->rows && resposta )
      {
         matriz1->iy = 0;
         while ( matriz1->iy < matriz1->columns && resposta )
         {
            if ( matriz1->data [ matriz1->ix ][ matriz1->iy ] != 0 )
            {
               resposta = false;
            } // end if
            matriz1->iy = matriz1->iy + 1;
         } // end while
         matriz1->ix = matriz1->ix + 1;
      } // end while
   } // end if
   return ( resposta );
} // end matrixZero ( )

/**
   Method_17 (1017) - Testar se matriz so' contem zeros.
*/
void method_17 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   bool resposta = false;

// identificar
   IO_id ( "Method_17 (1017) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   if ( matriz1 != NULL )
   {
      IO_printf ( "\nMatriz (MATRIZ1.TXT):\n" );
      printIntMatrix ( matriz1 );

      resposta = matrixZero ( matriz1 );
      if ( resposta )
      {
         IO_printf ( "\nResultado: A matriz contem APENAS zeros.\n" );
      }
      else
      {
         IO_printf ( "\nResultado: A matriz NAO contem apenas zeros.\n" );
      } // end if

      free_int_Matrix ( matriz1 );
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_17 ( )

/**
   matrixCompare - Testar a igualdade de duas matrizes.
   @return true se forem iguais, false caso contrario
   @param matriz1 - primeira matriz
   @param matriz2 - segunda matriz
*/
bool matrixCompare ( ref_int_Matrix matriz1, ref_int_Matrix matriz2 )
{
   bool resposta = false;
   if ( matriz1 == NULL || matriz1->data == NULL ||
        matriz2 == NULL || matriz2->data == NULL )
   {
      IO_printf ( "\nERRO: Matrizes invalidas.\n" );
   }
   else
   {
      if ( matriz1->rows != matriz2->rows || matriz1->columns != matriz2->columns )
      {
         IO_printf ( "\nAviso: Dimensoes incompativeis.\n" );
         resposta = false;
      }
      else
      {
         resposta = true;
         matriz1->ix = 0;
         while ( matriz1->ix < matriz1->rows && resposta )
         {
            matriz1->iy = 0;
            while ( matriz1->iy < matriz1->columns && resposta )
            {
               if ( matriz1->data [ matriz1->ix ][ matriz1->iy ] != matriz2->data [ matriz1->ix ][ matriz1->iy ] )
               {
                  resposta = false;
               } // end if
               matriz1->iy = matriz1->iy + 1;
            } // end while
            matriz1->ix = matriz1->ix + 1;
         } // end while
      } // end if
   } // end if
   return ( resposta );
} // end matrixCompare ( )

/**
   Method_18 (1018) - Comparar duas matrizes lidas de arquivos.
*/
void method_18 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   ref_int_Matrix matriz2 = NULL;
   bool resposta = false;

// identificar
   IO_id ( "Method_18 (1018) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   matriz2 = readMatrixFromFile ( "MATRIZ2.TXT" );

   if ( matriz1 != NULL && matriz2 != NULL )
   {
      IO_printf ( "\nMatriz 1 (MATRIZ1.TXT):\n" );
      printIntMatrix ( matriz1 );
      IO_printf ( "\nMatriz 2 (MATRIZ2.TXT):\n" );
      printIntMatrix ( matriz2 );

      resposta = matrixCompare ( matriz1, matriz2 );
      if ( resposta )
      {
         IO_printf ( "\nResultado: As matrizes sao IGUAIS.\n" );
      }
      else
      {
         IO_printf ( "\nResultado: As matrizes sao DIFERENTES.\n" );
      } // end if
   } // end if

// reciclar espaco
   free_int_Matrix ( matriz1 );
   free_int_Matrix ( matriz2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_18 ( )

/**
   matrixAdd - Somar duas matrizes, com a segunda multiplicada por uma constante.
   @return referencia para a matriz soma
   @param matriz1 - primeira matriz
   @param k - constante multiplicadora
   @param matriz2 - segunda matriz
*/
ref_int_Matrix matrixAdd ( ref_int_Matrix matriz1, int k, ref_int_Matrix matriz2 )
{
   ref_int_Matrix soma = NULL;
   if ( matriz1 == NULL || matriz1->data == NULL ||
        matriz2 == NULL || matriz2->data == NULL )
   {
      IO_printf ( "\nERRO: Dados ausentes.\n" );
   }
   else
   {
      if ( matriz1->rows != matriz2->rows || matriz1->columns != matriz2->columns )
      {
         IO_printf ( "\nERRO: Dimensoes incompativeis para soma.\n" );
      }
      else
      {
         soma = new_int_Matrix ( matriz1->rows, matriz1->columns );
         if ( soma != NULL && soma->data != NULL )
         {
            for ( soma->ix = 0; soma->ix < soma->rows; soma->ix = soma->ix + 1 )
            {
               for ( soma->iy = 0; soma->iy < soma->columns; soma->iy = soma->iy + 1 )
               {
                  soma->data [ soma->ix ][ soma->iy ]
                  = matriz1->data [ soma->ix ][ soma->iy ] + ( k * matriz2->data [ soma->ix ][ soma->iy ] );
               } // end for
            } // end for
         } // end if
      } // end if
   } // end if
   return ( soma );
} // end matrixAdd ( )

/**
   Method_19 (1019) - Somar duas matrizes (matriz1 + (-2 * matriz2)).
*/
void method_19 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   ref_int_Matrix matriz2 = NULL;
   ref_int_Matrix soma    = NULL;

// identificar
   IO_id ( "Method_19 (1019) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   matriz2 = readMatrixFromFile ( "MATRIZ2.TXT" );

   if ( matriz1 != NULL && matriz2 != NULL )
   {
      soma = matrixAdd ( matriz1, -2, matriz2 );
      if ( soma != NULL )
      {
         IO_printf ( "\nMatriz 1:\n" );
         printIntMatrix ( matriz1 );
         IO_printf ( "\nMatriz 2:\n" );
         printIntMatrix ( matriz2 );
         IO_printf ( "\nSoma (Matriz1 + (-2) * Matriz2):\n" );
         printIntMatrix ( soma );
         free_int_Matrix ( soma );
      } // end if
   } // end if

// reciclar espaco
   free_int_Matrix ( matriz1 );
   free_int_Matrix ( matriz2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_19 ( )

/**
   matrixProduct - Obter o produto de duas matrizes.
   @return referencia para a matriz produto
   @param matriz1 - primeira matriz
   @param matriz2 - segunda matriz
*/
ref_int_Matrix matrixProduct ( ref_int_Matrix matriz1, ref_int_Matrix matriz2 )
{
   ref_int_Matrix produto = NULL;
   int k = 0;

   if ( matriz1 == NULL || matriz1->data == NULL ||
        matriz2 == NULL || matriz2->data == NULL )
   {
      IO_printf ( "\nERRO: Dados ausentes.\n" );
   }
   else
   {
      if ( matriz1->columns != matriz2->rows )
      {
         IO_printf ( "\nERRO: Dimensoes incompativeis para produto (%dx%d e %dx%d).\n",
                     matriz1->rows, matriz1->columns, matriz2->rows, matriz2->columns );
      }
      else
      {
         produto = new_int_Matrix ( matriz1->rows, matriz2->columns );
         if ( produto != NULL && produto->data != NULL )
         {
            for ( produto->ix = 0; produto->ix < produto->rows; produto->ix = produto->ix + 1 )
            {
               for ( produto->iy = 0; produto->iy < produto->columns; produto->iy = produto->iy + 1 )
               {
                  produto->data [ produto->ix ][ produto->iy ] = 0;
                  for ( k = 0; k < matriz1->columns; k = k + 1 )
                  {
                     produto->data [ produto->ix ][ produto->iy ]
                     = produto->data [ produto->ix ][ produto->iy ]
                       + ( matriz1->data [ produto->ix ][ k ] * matriz2->data [ k ][ produto->iy ] );
                  } // end for
               } // end for
            } // end for
         } // end if
      } // end if
   } // end if
   return ( produto );
} // end matrixProduct ( )

/**
   Method_20 (1020) - Multiplicar duas matrizes lidas de arquivos.
*/
void method_20 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   ref_int_Matrix matriz2 = NULL;
   ref_int_Matrix produto = NULL;

// identificar
   IO_id ( "Method_20 (1020) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   matriz2 = readMatrixFromFile ( "MATRIZ2.TXT" );

   if ( matriz1 != NULL && matriz2 != NULL )
   {
      produto = matrixProduct ( matriz1, matriz2 );
      if ( produto != NULL )
      {
         IO_printf ( "\nMatriz 1:\n" );
         printIntMatrix ( matriz1 );
         IO_printf ( "\nMatriz 2:\n" );
         printIntMatrix ( matriz2 );
         IO_printf ( "\nProduto (Matriz1 * Matriz2):\n" );
         printIntMatrix ( produto );
         free_int_Matrix ( produto );
      } // end if
   } // end if

// reciclar espaco
   free_int_Matrix ( matriz1 );
   free_int_Matrix ( matriz2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_20 ( )

/**
   sortArrayDown - Colocar um arranjo em ordem decrescente pelo metodo de trocas.
   @return referencia para um novo arranjo ordenado
   @param arranjo - referencia para o arranjo original
*/
ref_int_Array sortArrayDown ( ref_int_Array arranjo )
{
   ref_int_Array ordenado = NULL;
   int i   = 0;
   int j   = 0;
   int tmp = 0;

   if ( arranjo == NULL || arranjo->data == NULL || arranjo->length <= 0 )
   {
      IO_printf ( "\nERRO: Arranjo invalido.\n" );
   }
   else
   {
      ordenado = new_int_Array ( arranjo->length );
      if ( ordenado != NULL && ordenado->data != NULL )
      {
         // copiar elementos
         for ( i = 0; i < arranjo->length; i = i + 1 )
         {
            ordenado->data [ i ] = arranjo->data [ i ];
         } // end for

         // ordenar pelo metodo de trocas (Bubble Sort decrescente)
         for ( i = 0; i < ( ordenado->length - 1 ); i = i + 1 )
         {
            for ( j = 0; j < ( ordenado->length - 1 - i ); j = j + 1 )
            {
               if ( ordenado->data [ j ] < ordenado->data [ j + 1 ] )
               {
                  tmp                      = ordenado->data [ j ];
                  ordenado->data [ j ]     = ordenado->data [ j + 1 ];
                  ordenado->data [ j + 1 ] = tmp;
               } // end if
            } // end for
         } // end for
      } // end if
   } // end if
   return ( ordenado );
} // end sortArrayDown ( )

/**
   Method_E1 (10E1) - Ordenar arranjo em ordem decrescente.
*/
void method_E1 ( void )
{
// definir dados
   ref_int_Array arranjo1 = NULL;
   ref_int_Array ordenado = NULL;

// identificar
   IO_id ( "Method_E1 (10E1) - v0.0" );

// ler dados
   arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
   if ( arranjo1 != NULL )
   {
      ordenado = sortArrayDown ( arranjo1 );
      if ( ordenado != NULL )
      {
         IO_printf ( "\nArranjo Original (DADOS1.TXT):\n" );
         printIntArray ( arranjo1 );
         IO_printf ( "\nArranjo Ordenado Decrescente:\n" );
         printIntArray ( ordenado );
         free_int_Array ( ordenado );
      } // end if
      free_int_Array ( arranjo1 );
   } // end if

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_E1 ( )

/**
   identityMatrix - Testar se uma matriz e' igual a' matriz identidade.
   @return true se for matriz identidade, false caso contrario
   @param matriz - referencia para a matriz a ser testada
*/
bool identityMatrix ( ref_int_Matrix matriz )
{
   bool resposta = false;
   if ( matriz == NULL || matriz->data == NULL || matriz->rows <= 0 || matriz->columns <= 0 )
   {
      IO_printf ( "\nERRO: Matriz invalida.\n" );
   }
   else
   {
      if ( matriz->rows != matriz->columns )
      {
         IO_printf ( "\nAviso: A matriz nao e' quadrada (%dx%d).\n", matriz->rows, matriz->columns );
         resposta = false;
      }
      else
      {
         resposta = true;
         matriz->ix = 0;
         while ( matriz->ix < matriz->rows && resposta )
         {
            matriz->iy = 0;
            while ( matriz->iy < matriz->columns && resposta )
            {
               if ( matriz->ix == matriz->iy )
               {
                  if ( matriz->data [ matriz->ix ][ matriz->iy ] != 1 )
                  {
                     resposta = false;
                  } // end if
               }
               else
               {
                  if ( matriz->data [ matriz->ix ][ matriz->iy ] != 0 )
                  {
                     resposta = false;
                  } // end if
               } // end if
               matriz->iy = matriz->iy + 1;
            } // end while
            matriz->ix = matriz->ix + 1;
         } // end while
      } // end if
   } // end if
   return ( resposta );
} // end identityMatrix ( )

/**
   Method_E2 (10E2) - Testar se o produto de duas matrizes e' igual a' matriz identidade.
*/
void method_E2 ( void )
{
// definir dados
   ref_int_Matrix matriz1 = NULL;
   ref_int_Matrix matriz2 = NULL;
   ref_int_Matrix produto = NULL;
   bool resposta = false;

// identificar
   IO_id ( "Method_E2 (10E2) - v0.0" );

// ler dados
   matriz1 = readMatrixFromFile ( "MATRIZ1.TXT" );
   matriz2 = readMatrixFromFile ( "MATRIZ2.TXT" );

   if ( matriz1 != NULL && matriz2 != NULL )
   {
      produto  = matrixProduct ( matriz1, matriz2 );
      resposta = identityMatrix ( produto );

      IO_printf ( "\nMatriz 1:\n" );
      printIntMatrix ( matriz1 );
      IO_printf ( "\nMatriz 2:\n" );
      printIntMatrix ( matriz2 );
      IO_printf ( "\nProduto (Matriz1 * Matriz2):\n" );
      printIntMatrix ( produto );

      if ( resposta )
      {
         IO_printf ( "\nResultado: O produto E' igual a matriz identidade.\n" );
      }
      else
      {
         IO_printf ( "\nResultado: O produto NAO e' igual a matriz identidade.\n" );
      } // end if

      free_int_Matrix ( produto );
   } // end if

// reciclar espaco
   free_int_Matrix ( matriz1 );
   free_int_Matrix ( matriz2 );

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // end method_E2 ( )

/**
   Metodo auxiliar (Opcao 99) para gerar os arquivos de teste automaticamente.
*/
void criarArquivosDeTeste ( void )
{
   ref_int_Array a1 = new_int_Array ( 5 );
   ref_int_Array a2 = new_int_Array ( 5 );
   ref_int_Matrix m1 = new_int_Matrix ( 3, 3 );
   ref_int_Matrix m2 = new_int_Matrix ( 3, 3 );

   IO_id ( "Gerador de Arquivos de Teste - v0.0" );

   if ( a1 && a2 && m1 && m2 )
   {
      a1->data[0] = 10; a1->data[1] = 30; a1->data[2] = 20; a1->data[3] = 50; a1->data[4] = 40;
      a2->data[0] = 5;  a2->data[1] = 10; a2->data[2] = 15; a2->data[3] = 20; a2->data[4] = 25;
      fprintIntArray ( "DADOS.TXT",  a1 );
      fprintIntArray ( "DADOS1.TXT", a1 );
      fprintIntArray ( "DADOS2.TXT", a2 );

      m1->data[0][0] = 1; m1->data[0][1] = 0; m1->data[0][2] = 0;
      m1->data[1][0] = 0; m1->data[1][1] = 1; m1->data[1][2] = 0;
      m1->data[2][0] = 0; m1->data[2][1] = 0; m1->data[2][2] = 1;

      m2->data[0][0] = 1; m2->data[0][1] = 2; m2->data[0][2] = 3;
      m2->data[1][0] = 4; m2->data[1][1] = 5; m2->data[1][2] = 6;
      m2->data[2][0] = 7; m2->data[2][1] = 8; m2->data[2][2] = 9;

      fprintIntMatrix ( "MATRIZ1.TXT", m1 );
      fprintIntMatrix ( "MATRIZ2.TXT", m2 );

      IO_printf ( "\nArquivos DADOS.TXT, DADOS1.TXT, DADOS2.TXT, MATRIZ1.TXT e MATRIZ2.TXT criados com sucesso!\n" );
   } // end if

   free_int_Array ( a1 );
   free_int_Array ( a2 );
   free_int_Matrix ( m1 );
   free_int_Matrix ( m2 );

   IO_pause ( "Apertar ENTER para continuar" );
} // end criarArquivosDeTeste ( )

/**
   Method_00 - nao faz nada.
*/
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )

// ----------------------------------------------- funcao principal

/*
   Funcao principal.
   @return codigo de encerramento
*/
int main ( void )
{
// definir dado
   int x = 0;

// repetir ate desejar parar
   do
   {
      // identificar
      IO_id ( "EXEMPLO1011 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( " 0 - parar" );
      IO_println ( "11 - (1011) gerar valores aleatorios em intervalo e gravar em DADOS.TXT" );
      IO_println ( "12 - (1012) procurar valor inteiro em arranjo lido de DADOS.TXT" );
      IO_println ( "13 - (1013) comparar dois arranjos (DADOS1.TXT e DADOS2.TXT)" );
      IO_println ( "14 - (1014) somar dois arranjos com constante (DADOS1.TXT e DADOS2.TXT)" );
      IO_println ( "15 - (1015) verificar se arranjo (DADOS1.TXT) esta em ordem decrescente" );
      IO_println ( "16 - (1016) obter matriz transposta de MATRIZ1.TXT" );
      IO_println ( "17 - (1017) testar se MATRIZ1.TXT contem apenas zeros" );
      IO_println ( "18 - (1018) testar igualdade de duas matrizes (MATRIZ1.TXT e MATRIZ2.TXT)" );
      IO_println ( "19 - (1019) somar duas matrizes com constante (MATRIZ1.TXT e MATRIZ2.TXT)" );
      IO_println ( "20 - (1020) obter o produto de duas matrizes (MATRIZ1.TXT e MATRIZ2.TXT)" );
      IO_println ( "21 - (10E1) ordenar arranjo (DADOS1.TXT) em ordem decrescente" );
      IO_println ( "22 - (10E2) testar se o produto de duas matrizes e' a matriz identidade" );
      IO_println ( "99 - [AUX]  gerar arquivos DADOS1, DADOS2, MATRIZ1 e MATRIZ2 padroes" );
      IO_println ( "" );

      x = IO_readint ( "Entrar com uma opcao: " );

      // testar valor
      switch ( x )
      {
         case  0: method_00 ( ); break;
         case 11: method_11 ( ); break;
         case 12: method_12 ( ); break;
         case 13: method_13 ( ); break;
         case 14: method_14 ( ); break;
         case 15: method_15 ( ); break;
         case 16: method_16 ( ); break;
         case 17: method_17 ( ); break;
         case 18: method_18 ( ); break;
         case 19: method_19 ( ); break;
         case 20: method_20 ( ); break;
         case 21: method_E1 ( ); break;
         case 22: method_E2 ( ); break;
         case 99: criarArquivosDeTeste ( ); break;
         default:
            IO_pause ( "ERRO: Valor invalido." );
      } // end switch
   }
   while ( x != 0 );

// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // end main ( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
- Todos os lacos que podem encerrar antes do fim utilizam variavel booleana na
  condicao do while, respeitando a restricao de nao utilizar 'break'.
- Toda a memoria alocada dinamicamente com new_int_Array e new_int_Matrix e'
  liberada ao final de cada metodo com free_int_Array e free_int_Matrix.
---------------------------------------------- previsao de testes
a.) 1011: Intervalo [10, 50], N = 5 -> Gera 5 inteiros em DADOS.TXT.
b.) 1012: Procura valor 30 em DADOS.TXT -> Retorna verdadeiro/falso.
c.) 1013: Compara DADOS1.TXT e DADOS2.TXT -> Indica se sao iguais ou diferentes.
d.) 1014: Calcula DADOS1 + (-2 * DADOS2) -> Exibe arranjo resultante.
e.) 1015: Verifica se DADOS1.TXT e' decrescente -> Exibe resultado booleano.
f.) 1016: Transpoe MATRIZ1.TXT (MxN -> NxM) -> Exibe original e transposta.
g.) 1017: Verifica se MATRIZ1.TXT possui apenas zeros -> Exibe resultado booleano.
h.) 1018: Compara MATRIZ1.TXT e MATRIZ2.TXT -> Exibe resultado booleano.
i.) 1019: Calcula MATRIZ1 + (-2 * MATRIZ2) -> Exibe matriz resultante.
j.) 1020: Calcula MATRIZ1 * MATRIZ2 -> Exibe matriz produto.
k.) 10E1: Ordena DADOS1.TXT em ordem decrescente por trocas -> Exibe arranjo ordenado.
l.) 10E2: Verifica se MATRIZ1 * MATRIZ2 == Identidade -> Exibe resultado booleano.
---------------------------------------------- historico
Versao   Data        Modificacao
 0.1     13/10       esboco e implementacao completa do ED10
---------------------------------------------- testes
Versao   Teste
 0.1     01. ( OK )  Exercicios 1011 a 1020 e Extras 10E1 e 10E2
*/