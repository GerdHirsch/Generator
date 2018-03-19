#ifndef __APPLICATION_COMPONENTS_H__
#define __APPLICATION_COMPONENTS_H__

/*
 * Allgemeine Komponenten die die meisten Anwendungen benötigen
 */

namespace App
{
    struct HMI { static char const* name(){return "App::HMI";} };
    struct Model { static char const* name(){return "App::Model";} };
    struct DataBase { static char const* name(){return "App::DataBase";} };
}

#endif // __APPLICATION_COMPONENTS_H__
