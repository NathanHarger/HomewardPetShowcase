#include "configuration.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <string>
#include <QTextStream>
#include "animal.h"
using namespace std;
Configuration::Configuration()
{ 
   QFile file("://settings.txt");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;
    QTextStream in(&file);

     devkey = in.readLine();

    // read the shelter id from the config file
     shelterid = in.readLine();

     // read the animal types from the config file
    QString typeString = in.readLine();
        AnimalTypes = typeString.split(",");

    file.close();
    }

QString Configuration::getDevKey()
{
    return this->devkey;
}

QString Configuration::getShelterID()
{
    return this->shelterid;
}

QStringList Configuration::getAnimalTypes(){
    return AnimalTypes;
}

