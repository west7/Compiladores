# Análise sintática top-down

...

# Analisador sintático preditivo não-recursivo

É possível construir um analisador sintático preditivo não-recursivo usando: um *buffer de entrada*, uma *pilha explícita*, uma *tabela sintática* e e um *fluxo de saída*. O principal desafio deste analisador é, identificar a produção que deve ser aplicada a um não terminal.

Para isso, o analisador busca na **Tabela sintática** a produção a ser aplicada. Tal tabela é construída a partir de certas gramáticas.

O buffer de entrada contém a cadeia de caracteres a ser analisada, seguido de um sentinela (*$*) que indica o fim de entrada.

A pilha contém símbolos gramaticais onde o sentinela fica no fundo.

A tabela sintática é uma matriz M [A, a] cuja primeira dimensão contém não-terminais A e a segunda contém terminais a ou o sentinela $.

[modelo](modelo.canvas)

![](Pasted%20image%2020231211173402.png)
# Tabela sintática

Duas funções auxiliares participam da construção da Tabela sintática. São as funções **First()** e **Follow()**.

## First(primeiro)
O conjunto **First()** de ***α***, ou ***First(α)***, só contém terminais, de modo que:

- Se ***α*** é um **terminal**
	1.  First(α) = {α}

- Se ***α*** é um **não-terminal**
	1. α -> aβ, onde *a* é um terminal e *β* é uma cadeia qualquer, *a* ∈  First(α);
	2. α -> ε, ε ∈ First(α);
	3. α -> Y' Y'' ... Yn:
		1. Se Y' não produz ε, então First(Y') ∈ First(α);
		2. Se Y' produz ε, e Y'' não, First(Y') ∪ First(Y'') ∈ First(α);
		3. Assim por diante até Yn.

## Follow(seguinte)
O conjunto ***Follow()***, de um **não-terminal** **X**, ou ***Follow(X)***, é o conjunto de terminais que aparecem **imediatamente** depois de ***X***.

Como calcular o conjunto **Follow()** dos não-terminais de uma gramática *G*?

- Primeiro inserir o marcador sentinela *$* no conjunto Follow do símbolo de partida *S*.

Depois, para cada produção de cada não-terminal de *G*:
	1º Caso - Existe uma produção **A -> αDβ**, na qual **β** não tem uma produção **ε**, então:
		 ***Follow(D) = First(β)***
	2º Caso - Existe uma produção  **A -> αDβ**, na qual **β** tem uma produção **ε**, ou uma produção **A -> αD**, então:
		***Follow(D) = Follow(A)***


