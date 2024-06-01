# Gramática livre de contexto

Uma gramática livre de contexto é composta por terminais, não-terminais, um símbolo de partida e produções nos quais:

1. Os **terminais** ([[tokens]]) são unidades básicas para formação de cadeias.
2. Os **não-terminais** são variáveis sintáticas que identificam as cadeias de tokens e impõe a estrutura hierárquica da linguagem.
3. Um dentre os não-terminais é designado **símbolo de partida** (normalmente o primeiro), e a cadeia de tokens geradas por ele é a linguagem definida pela gramática.
4. As **produções** estabelecem as relações entre terminais e não-terminais. Cada produção é composta por ***1*** não terminal seguido de uma seta e, logo após, uma cadeia de terminais e não terminais.
---
>Nota:  **Como diferenciar uma Gramática livre de contexto (GLC) de uma Gramática não livre de contexto (GLNC)?**

Simples, as GLC's seguem a seguinte estrutura:

S -> α 

Onde *S* é um não terminal e *α* é uma cadeia de terminais e não-terminais, portanto se *S* não for único a gramática em questão será uma GLNC. Exemplos:

- S -> aSb | ε   -   (**GLC**)

- aS -> Sa | b   -   (**GLNC**)

- SB -> Sa | b   -   (**GLNC**)
   B -> b | ε

> Em suma: **GLC** tem ***apenas um*** não-terminal no lado esquerdo de uma produção. 
---

# Derivações
---
Seja ***E*** um não-terminal e ***E* -> α1 | α2 | ... | αN*** as produções-*E*  e **σ = β E γ**. É dito que ***σ*** deriva ***β αi γ***, e notamos que ***σ ⇒ β αi γ***, se a instância de ***E*** em ***σ*** é equivalente a alguma das produções-*E*. Uma sequência de substituições em σ que resulte em X é chamada derivação de X a partir de σ.

Se α1 ⇒ α2 ⇒ . . . ⇒ αN , então α1 deriva αN . O símbolo '⇒' significa “deriva em um passo”. O símbolo ' * ⇒ ' significa “deriva em zero ou mais passos” e o símbolo ' + ⇒ ' significa “deriva em um ou mais passos”. A derivação em zero ou mais passos tem duas importantes propriedades:
1. α * ⇒ α para qualquer cadeia α
2. se α * ⇒ β e β * ⇒ γ, então α * ⇒ γ

---

