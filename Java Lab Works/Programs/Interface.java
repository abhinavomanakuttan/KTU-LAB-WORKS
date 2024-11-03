/*
    In this exercise you will create a hierarchy of 
animals that is rooted in an abstract class Animal. 
Several of the animal classes will implement an 
interface called Pet. You will experiment with 
variations of these animals, their methods, and 
polymorphism
 */


// Interface for Pet behavior
interface Pet {
    void play();
}

// Abstract class Animal
abstract class Animal {
    String name;

    // Constructor for Animal
    public Animal(String name) {
        this.name = name;
    }

    // Abstract method makeSound, to be implemented by subclasses
    abstract void makeSound();

    // Method to simulate eating
    void eat() {
        System.out.println(name + " is eating.");
    }
}

// Dog class, extends Animal and implements Pet
class Dog extends Animal implements Pet {

    public Dog(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println(name + " says: Woof!");
    }

    @Override
    public void play() {
        System.out.println(name + " loves to play fetch!");
    }
}

// Cat class, extends Animal and implements Pet
class Cat extends Animal implements Pet {

    public Cat(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println(name + " says: Meow!");
    }

    @Override
    public void play() {
        System.out.println(name + " loves to play with a ball of yarn!");
    }
}

// Fish class, extends Animal but does not implement Pet
class Fish extends Animal {

    public Fish(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println(name + " makes no sound.");
    }

    // Additional method specific to Fish
    void swim() {
        System.out.println(name + " is swimming.");
    }
}

// Main class to demonstrate polymorphism
public class Interface{
    public static void main(String[] args) {
        // Creating objects of different animal types
        Animal dog = new Dog("Buddy");
        Animal cat = new Cat("Whiskers");
        Animal fish = new Fish("Nemo");

        // Array to hold animals for polymorphic behavior
        Animal[] animals = {dog, cat, fish};

        for (Animal animal : animals) {
            animal.makeSound();
            animal.eat();

            // Checking if the animal is also a Pet
            if (animal instanceof Pet) {
                ((Pet) animal).play();
            }

            // Checking if the animal is a Fish
            if (animal instanceof Fish) {
                ((Fish) animal).swim();
            }

            System.out.println(); // For line separation
        }
    }
}

 
