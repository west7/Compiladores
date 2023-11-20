## Associatividade de operadores

Quando um operando está simultaneamente à esquerda e à direita de dois operadores é preciso decidir para qual operador ele pertence. Na expressão `1 + 2 - 3` não se sabe a qual operador o `2` pertence. Uma operação é associativa à esquerda se `a op b op c = (a op b) op c`. Na maioria das linguagens os operadores aritméticos são associativos à esquerda. Uma operação é associativa à direita se `a op b op c = a op (b op c)`. A operação de atribuição (`=`) da linguagem C, por exemplo, é associativa à direita. `a = b = c`. ^ddd9a7
## Precedência de operadores

Existem algumas expressões que contém ambiguidades que não são resolvida por meio da associatividade. Por isso, dizemos que, um operador `x` têm maior precedência que um operador `z`, se `x`captura os operandos antes do que `z`. Na aritmética a multiplicação e a divisão tem maior precedência que a adição e a subtração. Se dois operadores tem a mesma precedência a ordem é definida pela associatividade. 
^694c21
#### Construção da gramática

- É possível construir uma gramática com precedência de operadores a partir das seguintes regras:
	1. Construa uma tabela com a associatividade e precedência dos operadores, em ordem decrescente de precedência:
		associatividade à esquerda (+, - )
		associatividade à esquerda ( * , / )
	2. Crie um **não-terminal** para cada nível (*expr, term*) e um não terminal extra para unidades básicas da expressão (*fator*):
		*fator* -> **digito** | (*expr*)
	3. Defina as produções para o último terminal criado a partir dos níveis de precedência de operadores:
		*term* -> *term* * *fator* |
			      *term* / *fator*  |
			      *fator*
	4. Faça o mesmo para os demais operadores:
		*expr* -> *expr* + *term* |
			      *expr* - *term* |
			      *term*

No final obtêm-se a seguinte gramática G:
(G)
		*expr* ->  *expr* + *term* |
			          *expr* - *term*  |
			          *term*
		*term* ->  *term* * *fator* |
			          *term* / *fator*  |
			          *fator*
		*fator* ->  **digito** | ( *expr* )

A presença de parêntesis na definição de *<u>fator</u>* permite escrever expressões com níveis arbitrários de aninhamento, sendo que os parêntesis tem precedência sobre todos os operadores definidos.

>**Importante**: Note que operadores com **associatividade à esquerda**, o **não terminal**, associado a ele, aparece à **esquerda** do operador **(*expr*** ->  ***expr*** + *term*), sendo o contrário também verdadeiro. Além de que, operadores sempre aparecem em ordem decrescente de **precedência**, ou seja, o símbolo de partida sempre conterá os operadores de menor precedência, daquela gramática.

