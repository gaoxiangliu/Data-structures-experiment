/************************************************************************
 *              Stack Appliance--Solutions of Labyrinth                 *
 *        Print one solution(simple path) of a given labyrinth          *
 *             This head file is only for this appliance                *
 *                     Developed by Gaoxinag Liu                        *
 *     The author has no responsibility for the errors or omissions.    *
 *                Only for sutdy or education purpose.                  *
 ************************************************************************/

#pragma once

#include<stdbool.h>

#define STACK_INIT_SIZE 100		//initial quantity of elements
#define STACK_INCREMENT 10		//increment
#define ELEMENT_SIZE    sizeof(Element) 

typedef struct
{
	int x;						//X	axis
	int y;						//Y axis
} Position;						//block's position(coordinate)
typedef struct
{
	int order;					//the order of a corridor block
								//that on the path
	Position seat;				//the position coordinate of the block
	int dir;					//the next direction of a corridor block
								//1:east,2:south,3:west,4:north
} Element;						//Element of the stack
typedef struct
{
	Element *base;				//stack bottom pointer
								//base will be NULL before construction
								//and after destroy
	Element *top;				//stack top pointer
								//it points the first element over the top one
								//top==base when stack is emtpy
	int stacksize;				//the occupied memory room
								//based on the unit of element
								//0:befroe construction and after destroy
} SqStack;

//function prototypes

//operation:initialize an empty stack
//pre-condition:s poionts an uninitialized stack
//post-condition:return true if it succeeds, false otherwise
bool InitStack(SqStack *s);

//operation:destroy a stack
//pre-condition:s points a stack
//post-conditoin:the stack will no longer exist
//				 return true if it succeeds, false otherwise
bool DestroyStack(SqStack *s);

//operation:wipe a stack to empty
//pre-condition:s points to a non-empty stack
//post-condition:return true if it succeeds, false otherwise
bool ClearStack(SqStack *s);

//operation:decide whether the stack is empty
//pre-conditoin:s points to a stack(pointer to const type)
//post-condition:return true if it is emtpy, false otherwise
//				 nothing will be changed
bool StackIsEmpty(const SqStack *s);

//operation:get the occupied memory based on element, namely, stack's lenght
//pre-condition:s points to a stack(pointer to const type)
//post-condition:return an integer, nothing will be changed
int StackLength(const SqStack *s);

//operatoin:get the top element of the stack
//pre-condition:s points to a const stack
//post-condition:e will carry the top element if the stack is not empty
//				 and return true, false otherwise
bool GetTop(const SqStack *s, Element *e);

//operatoin:insert a new element to a stack
//pre-condition:s points to a stack, e is the new element will be instered
//post-condition:reutrn true if it succeeds, false otherwise
bool Push(SqStack *s, const Element *e);

//operation:fetch the top element of the stack
//pre-condition:s points to a stack
//post-condition:e will carry to top element if the stack is not empty
//				 and return true, otherwise, false
bool Pop(SqStack *s, Element *e);

//operation:apply a function to all the elements in the stack(from bottom to top)
//pre-condition:s points to a stack, visit points to a function
//post-condition:return true if the stack is not empty and function is
//				 successfully applied to each element
bool StackTraverse(SqStack *s, void(*visit)(Element *));