# Análise
A análise é composta por 3 fases:
	1. **Análise Léxica (ou Linear)** - O fluxo de caracteres que compõe o programa é lido de forma sequencial e agrupado em [Tokens](Tokens.md)
	2. **Análise sintática (ou Hierárquica)** - Os [Tokens](Tokens.md) são agrupados hierarquicamente em coleções com significados coletivos.
	3. **Análise Semântica** - Verifica se os componentes se combinam de maneira significativa.
## Análise Léxica  
Na seguinte sentença a análise léxica identificaria os seguintes [Tokens](Tokens.md):
> `F = 1.8 * C + 32`
^6d75e1
1. O identificador `F` ;
2. O símbolo de atribuição `=`; 
3. O número `1.8`;
4. O símbolo de multiplicação `*`;
5. O identificador `C`;
6. O símbolo de adição `+`;
7. O número `32`;
## Análise sintática
Agrupa de maneira hierárquica os tokens, geralmente em uma árvore gramatical. Pode ser implementada pelas seguintes regras recursivas:
	1. Qualquer identificador é uma expressão;
	2. Qualquer número é uma expressão;
	3. Se `E1` e `E2` são expressões, então `E1 + E2` e `E1 * E2` também são expressões;
	4. Se `I` é um identificador  e `E` é uma expressão então `I = E`é um enunciado;

[Árvore Sintática](Árvore%20Sintática.canvas)

![](../assets/Pasted%20image%2020231119220636.png)

## Análise semântica
A análise semântica verifica possíveis erros semânticos no programa fonte. Ela usa a árvore sintática para atribuir tipos aos operandos e operadores da árvore, além de fazer a verificação de tipos. Caso os tipos não sejam compatíveis ela pode sinalizar erros ou realizar uma promoção/conversão de tipo. Por exemplo, na expressão: `F = 1.8 * C + 32`, o operando a esquerda da soma tem tipo `float`, já o operando a direita da soma tem tipo `int`, portanto o valor `32`deve ser promovido a `float`.

[Árvore Gramatical](Árvore%20Gramatical.canvas)

![](../assets/Pasted%20image%2020231119220731.png)

---
# Síntese
A síntese é composta por 3 fases:
1. **Gerador de código intermediário** - Nesta fase, o compilador cria um código intermediário que serve como uma **representação abstrata** do programa-fonte. Esse código é projetado para ser **independente da arquitetura** específica do hardware de destino;
2. **Otimizador de código** - O código intermediário passa por um otimizador, que realiza diversas transformações para melhorar a eficiência do código. Isso pode incluir eliminação de código morto, propagação de constantes, otimização de laços, entre outras técnicas;
3. **Gerador de código** - Com base no código otimizado, o compilador gera o código de máquina ou código de linguagem de montagem específico para a arquitetura do hardware de destino. Essa fase também pode envolver a alocação de registros, manipulação de pilha, e outras considerações específicas da arquitetura.compiladores 1

[[vault/Aula01/-main|voltar.]]