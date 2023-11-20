Uma máquina de pilha abstrata possui memórias separadas para dados e instruções, e todas as operações são realizadas sobre os valores de uma pilha. 

As instruções são divididas em 3 classes:
	1. Aritmética inteira; 
	2. Manipulação da pilha; 
	3. Fluxo de controle.
	
A máquina de pilha precisa implementar cada operação da linguagem intermediária. Operações simples como adição e subtração são implementadas diretamente. Operações mais sofisticadas devem ser implementadas como uma sequência de instruções da máquina de pilha. Para simplificar assuma que exista uma instrução para cada operação da linguagem. A avaliação segue da esquerda para direita empilhando os operandos, quando encontra um operador desempilha o(s) operando(s), realiza a operação e empilha o resultado novamente.

[Exemplo máquina de pilha](Exemplo%20máquina%20de%20pilha.canvas)

A máquina pode ser a saída da do [gerador de código intermediário](Fases%20de%20um%20compilador.md). Que será o substrato para a interface de vanguarda construir o programa alvo.

## Aritmética inteira
As instruções de aritmética inteira são instruções simples, como exemplo as seguintes:

|Instrução | Significado|
|--|--|
| + | Adição|
| - | Subtração |
| * | Multiplicação|
| / | Divisão|
| % | Módulo |

## Manipulação da pilha
Uma máquina de pilha suporta as seguintes instruções de manipulação:

|Instrução | Significado|
|----------|------------|
|push v    |   empilha v|
|pop       | desempilha o valor no topo|
|valor-R v| empilha o valor-R de v|
|valor-L v| empilha o valor-L de v|
|=| O valor-R do topo da pilha é armazenado no valor-L do subtopo(elemento logo abaixo do topo)
|copiar| empilha o valor do topo da pilha|

## Tradução de expressões
O código para avaliar uma expressão da máquina de pilha ligação direta com a notação posfixa, por exemplo:	A expressão `a + b`, é traduzida como:

``` 
	valor-R a
	valor-R b
	+
```

-> As atribuições são traduzidas da seguinte maneira: o valor-L do identificador é empilhado, a expressão à direita é avaliada e o seu valor r é atribuído ao identificador;
-> Formalmente, cmd → id := expr { cmd.t := "valor-l" || id.lexema || expr.t || ":=" }

Tradução para expressão: `F = 9 * C / 5 + 32`

```
valor-L F
push 9
valor-R C
*
push 5
/
push 32
+
=
```

## Fluxo de controle
A máquina de pilha abstrata executa as instruções sequencialmente, na ordem em que forem dadas.
Há três maneiras de especificar um salto:
	1. o operando da instrução fornece o endereço da localização alvo;
	2. o operando da instrução fornece a distância relativa (positiva ou negativa) a ser saltada;
	3. o alvo é especificado simbolicamente (rótulos).
Nas duas primeiras formas uma alternativa é especificar que o salto está no topo da pilha. A terceira forma é a mais simples e mais utilizada, pois não há necessidade de se recalcular endereços caso haja alguma modificação no código (como uma otimização,  por exemplo).

**Instruções de fluxo de controle**:

|Instrução | Significado|
|--|--|
|rótulo r| especifica o rótulo r como possível alvo de saltos|
|goto r| salta imediatamente para o rótulo r|
|gofalse r | desempilha o topo e salta se o valor for falso(igual a zero)|
|gotrue r| desempilha o topo da pilha e salta caso valor for verdadeiro(diferente de zero)|
|parar| encerra a execução|

[Tradução de condicionais e laços](Tradução%20de%20condicionais%20e%20laços.canvas)

###  Unicidade de rótulos
-> Os rótulos `saida` e `teste` que ilustram os gabaritos das condicionais e dos laços devem ser únicos, para evitar possíveis ambiguidades 
-> É preciso, portanto, de uma estratégia que torne tais rótulos únicos durante a tradução 
-> Seja `novoRotulo` um procedimento que gera, a cada chamada, um novo rótulo único 
-> A ação semântica associada ao comando if assumiria a seguinte forma: 
	cmd → if expr then cmd1 { saida := novoRotulo; 
	cmd.t := expr.t 
	|| "gofalse" saida 
	|| cmd1.t 
	|| "rotulo" saida }

# Código máquina de pilha
- Exemplo de como é um código de máquina de pilha na prática

```C
	int M = 1;
	while (a != 1){
		if(a % 2 == 0)
			a /= 2;
		else
			a = a * 3 + 1;
		M++;
	}
```

- O código, em C, acima gera o seguinte código de máquina de pilha:

```pseucódigo
	1. valorL M
	2. push 1
	3. =
	4. rotulo while
	5. valorR a
	6. push 1
	7. -
	8. gofalse saida
	9. valorR a
	10. push 2
	11. %
	12. gotrue else
	13. valorL a
	14. valorR a
	15. push 2
	16. /
	17. =
	18. goto if_saida
	19. rotulo else
	20. valorL a
	21. valorR a
	22. push 3
	23. *
	24. push 1
	25. +
	26. =
	27. rotulo if_saida
	28. valorL M
	29. valorR M
	30. push 1
	31. +
	32. goto while
	33. rotulo saida
	34. parar
```

Note que, a partir do pseudocódigo acima, já muito fácil converte-lo para linguagem de máquina ([[assembly]]).