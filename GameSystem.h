#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include <QObject>

//二次元配列エイリアス
template <class T>
using Field = QVector<QVector<T>>;

class GameSystem
{
public:
    const static int MAP_WIDTH  = 17;
    const static int MAP_HEIGHT = 15;

    //接続状態
    enum class CONNECTING_STATUS{
        FINISHED,
        CONTINUE,
    };
    //マップ上に存在する物体
    enum class MAP_OBJECT{
        NOTHING,
        HOT    ,
        COOL   ,
        BLOCK  ,
        ITEM   ,
    };
    //マップ上に描画する非物体
    enum class MAP_OVERLAY{
        NOTHING,
        LOOK,
        SEACH,
        GETREADY,
    };

    //クライアントの行動
    struct Method{
        //クライアントの行動
        enum class ACTION{
            WALK,
            LOOK,
            SEACH,
            PUT,
            UNKNOWN
        };
        //方向
        enum class ROTE{
            UP,
            DOWN,
            RIGHT,
            LEFT,
            UNKNOWN
        };
        ACTION action;
        ROTE   rote;
        static Method fromString(const QString& str);
    };
    //周辺情報
    struct AroundData{
        CONNECTING_STATUS connect;
        MAP_OBJECT data[9];

        QString toString();
    };
};

#endif // GAMESYSTEM_H
