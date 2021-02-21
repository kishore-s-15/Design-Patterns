package com.kishore;

public class App 
{
    public static void main( String[] args )
    {
        Singleton obj2 = Singleton.getInstance("Bar");
        Singleton obj1 = Singleton.getInstance("Foo");

        System.out.println("Obj 1 Value : " + obj1.value);
        System.out.println("Obj 2 Value : " + obj2.value);
    }
}
