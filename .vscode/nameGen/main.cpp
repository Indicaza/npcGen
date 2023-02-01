#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <sstream>

std::mt19937 rng;

std::string readNamesFromFile(std::string filepath)
{
    std::vector<std::string> names;
    std::ifstream file(filepath);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name;
        while (std::getline(ss, name, ','))
        {
            names.push_back(name);
        }
    }

    std::uniform_int_distribution<int> dist(0, names.size() - 1);
    return names[dist(rng)];
}

std::string generateName(std::string race, std::string gender)
{
    std::string name;
    std::vector<std::string> names;
    if (gender == "male")
    {
        if (race == "human")
        {
            names = readNamesFromFile("human_male_names.csv");
        }
        else if (race == "elf")
        {
            names = readNamesFromFile("elf_male_names.csv");
        }
        else if (race == "dwarf")
        {
            names = readNamesFromFile("dwarf_male_names.csv");
        }
        else if (race == "goblin")
        {
            names = readNamesFromFile("goblin_male_names.csv");
        }
        else if (race == "orc")
        {
            names = readNamesFromFile("orc_male_names.csv");
        }
        else if (race == "gnome")
        {
            names = readNamesFromFile("gnome_male_names.csv");
        }
    }
    else if (gender == "female")
    {
        if (race == "human")
        {
            names = readNamesFromFile("human_female_names.csv");
        }
        else if (race == "elf")
        {
            names = readNamesFromFile("elf_female_names.csv");
        }
        else if (race == "dwarf")
        {
            names = readNamesFromFile("dwarf_female_names.csv");
        }
        else if (race == "goblin")
        {
            names = readNamesFromFile("goblin_female_names.csv");
        }
        else if (race == "orc")
        {
            names = readNamesFromFile("orc_female_names.csv");
        }
        else if (race == "gnome")
        {
            names = readNamesFromFile("gnome_female_names.csv");
        }
    }
    else if (gender == "androgynous")
    {
        if (race == "human")
        {
            names = readNamesFromFile("human_androgynous_names.csv");
        }
        else if (race == "elf")
        {
            names = readNamesFromFile("elf_androgynous_names.csv");
        }
        else if (race == "dwarf")
        {
            names = readNamesFromFile("dwarf_androgynous_names.csv");
        }
        else if (race == "goblin")
        {
            names = readNamesFromFile("goblin_androgynous_names.csv");
        }
        else if (race == "orc")
        {
            names = readNamesFromFile("orc_androgynous_names.csv");
        }
        else if (race == "gnome")
        {
            names = readNamesFromFile("gnome_androgynous_names.csv");
        }
    }
    std::uniform_int_distribution<int> dist(0, names.size() - 1);
    name = names[dist(rng)];
    return name;
}

int main()
{
    std::cout << generateName("dwarf", "male");
    return 0;
}