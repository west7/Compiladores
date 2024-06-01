# Definição da sintaxe

Uma gramática deve descrever a disposição hierárquica de seus elementos. Por exemplo na linguagem C:
	O comando `if-else` têm a forma: 
		`if (expressão) comando else comando`.
	E pode ser representado como:
		cmd -> *if* (expr) cmd *else* cmd
A expressão acima é um regra de produção, onde a seta "->" significa "pode ter a forma". Os elementos léxicos da produção são chamados [[Tokens|tokens]] ou **terminais** e variáveis como `cmd`ou `expr` são **não-terminais**.
## Componentes da gramática livre de contexto
1. Conjunto de [[Tokens|tokens]] denominados terminais;
2. Conjunto de não terminais;
3. Conjunto de produções. Cada produção é definida a partir de um não terminal, ou seja após a -> podem existir uma ou mais produções que são geradas a partir do não terminal(definido a esquerda da seta);
4. Designação de um símbolo de partida (o primeiro não terminal que aparece de cima para baixo).
## Convenções de uma gramática livre de contexto
- A gramática é uma lista de produções;
- O símbolo de partida é a primeira produção da lista;
- Dígitos, símbolos e palavras em negrito são terminais;
- Não terminais são grafados em itálico;
- Demais símbolos são tokens;
- Produções distintas de um mesmo não terminal são separadas por ' | ' (ou).

#### Exemplo
Considere a seguinte gramática para expressões infixas:
	*expr* -> *expr* + *digito* | *expr* - *digito* | *digito*
	*digito* -> **0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9**
	 ^a1df6d
- Os tokens são os dez dígitos(0..9) e os símbolos '+' e '-'.
- Os não terminais são *expr* e *digito*.
- O símbolo de partida é ***expr***.

## Árvore gramatical
Dada uma gramática livre de contexto, uma árvore possui as seguintes regras
	1. A raiz é rotula pelo símbolo de partida;
	2. Cada folha é rotulada por um token ou por `e`(vazio);
	3. Cada nó interior é rotulado por um não terminal;
	4. Se A é um não-terminal que rotula um nó interior e X1, X2, . . . , XN são os rótulos de seus filhos (da esquerda para a direita), então A → X1 X2 . . . XN é uma produção.

[[Árvore.canvas|Visualização da árvore para a expressão 1 - 2 + 3]]

![](Pasted%20image%2020231209113455.png)

As folhas da árvore gramatical, lidas da esquerda para a direita, o resultado é o produto daquela árvore, a cadeia derivada a partir da raiz não terminal. Este processo é denominado de análise gramatical ou análise sintática, daquela cadeia. Se uma gramática permite a construção de duas ou mais árvores que resultem naquela mesma cadeia, esta gramática é denominada **ambígua**. Contudo, a gramática descrita na [[Árvore.canvas|árvore]] não é ambígua, porém, caso a diferenciação entre *digito* e *expr*, seja removida, teríamos a seguinte gramática ambígua:

*expr* -> *expr* + *expr* | *expr* - *expr* | **0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9**  ^c33b4d

Que geraria as seguintes [[Árvore ambígua.canvas|árvores]] ambíguas.

![](Pasted%20image%2020231209113559.png)

Note que uma única expressão é capaz de gerar duas árvores que produzem a exata mesma expressão

## [[Operadores]]

Outra parte importante da definição da sintaxe é a definição e caracterização de operadores. Desde a [[Operadores#^ddd9a7|associatividade]] até a [[Operadores#^694c21|precedência]] de operadores, tudo é definido na gramática livre de contexto. 
