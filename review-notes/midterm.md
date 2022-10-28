# Exam Review Notes

## Computational Models

VonNeumann  (Harvard has a seperate code bus)
-> Where most languages live: Stack (grows in Frames as functions/methods are called, retreats when they return), Heap (garbage pail of information), Global memory (global / static vars live) also for literals/constants.
Neural Network
-> Edges and nodes are weighted graph ordered left to right.  Propegation rule: weight = sigma ( sum ( edge weights * incoming node weights)).   Hard problem is coming up with a good graph, designing and training such graphs is machine learning.

Quantum Computer (Probabilistic Computation)
x = 1 with prob .1, 2 with prob .9, ...
switch (x) {   case 1: case 2: ... }
## Language Types
Functional y=f(x)  (kind of need OO stuff to group things into x's and y's), Imperitive/Procedural (muffin recipe), Logical/constraint (focus on what the results need to be, not how to get them), Object-Oriented (oo groups ideas into "components") these fit better into the natural human model of thought.

## Regular Expressions
Describe sets of strings using a "calculus", starting from elemental sets epsilon (the empty set), a {"a"}.

xy = { s | s = a + b where a is in x and b is in y }
x|y = { s | s in x or s in y }
x{n,m} = like xxxx(n times)|xxxxx(n+ 1 times|...|xxxxxxx(m times)
x+=x{1,infinity}
x*=x{0,inifinty}
x?=x{0,1}

## Grammars

## Compiler / Interpreter Design Basics
