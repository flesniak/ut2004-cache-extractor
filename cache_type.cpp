#include "cache_type.h"

QString cache_type::getName(CacheType type)
{
QString name("Unknown");
switch(type)
  {
  case System     : name = "System";
                               break;
  case Map        : name = "Map";
                               break;
  case Animation  : name = "Animation";
                               break;
  case Texture    : name = "Texture";
                               break;
  case StaticMesh : name = "StaticMesh";
                               break;
  case Sound      : name = "Sound";
                               break;
  case Music      : name = "Music";
                               break;
  }
return(name);
}

QString cache_type::getName(QString fileext)
{
return(getName(getCacheTypeByFileExt(fileext)));
}

QString cache_type::getFileExt(CacheType type)
{
QString fileext("unknown");
switch(type)
  {
  case System     : fileext = "u";
                               break;
  case Map        : fileext = "ut2";
                               break;
  case Animation  : fileext = "ukx";
                               break;
  case Texture    : fileext = "utx";
                               break;
  case StaticMesh : fileext = "usx";
                               break;
  case Sound      : fileext = "uax";
                               break;
  case Music      : fileext = "ogg";
                               break;
  }
return(fileext);
}

QString cache_type::getFileExt(QString name)
{
return(getFileExt(getCacheTypeByName(name)));
}

CacheType cache_type::getCacheTypeByFileExt(QString fileext)
{
CacheType type = Unknown;
if( fileext.toLower() == "u" )   type = System;
if( fileext.toLower() == "ut2" ) type = Map;
if( fileext.toLower() == "ukx" ) type = Animation;
if( fileext.toLower() == "utx" ) type = Texture;
if( fileext.toLower() == "usx" ) type = StaticMesh;
if( fileext.toLower() == "uax" ) type = Sound;
if( fileext.toLower() == "ogg" ) type = Music;
return(type);
}

CacheType cache_type::getCacheTypeByName(QString name)
{
CacheType type = Unknown;
if( name.toLower() == "system" )     type = System;
if( name.toLower() == "map" )        type = Map;
if( name.toLower() == "animation" )  type = Animation;
if( name.toLower() == "texture" )    type = Texture;
if( name.toLower() == "staticmesh" ) type = StaticMesh;
if( name.toLower() == "sound" )      type = Sound;
if( name.toLower() == "music" )      type = Music;
return(type);
}
