#ifndef FILEWALKER
#define FILEWALKER

#include "Walker.h"
#include "Process.h"

class FileWalker : Walker {
public:
    FileWalker( Odometry *odo );
    void init();
    void setParam(double flwk[]);
    void execStart();

protected:
    enum FILE_NO{
        SNAP,
        BLOCK,
        IOT
    };

private:
    int mNo;
    int mComment;
};

#endif