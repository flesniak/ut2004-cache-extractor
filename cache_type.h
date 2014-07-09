#include <QtCore/QString>

enum CacheType { System, Map, Animation, Texture, StaticMesh, Sound, Music, Unknown };

class cache_type
{
  public:
    static QString getName(CacheType type);
    static QString getName(QString fileext);
    static QString getFileExt(CacheType type);
    static QString getFileExt(QString name);
    static CacheType getCacheTypeByFileExt(QString fileext);
    static CacheType getCacheTypeByName(QString name);
};
