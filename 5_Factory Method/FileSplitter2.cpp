

//具体类
class BinarySplitter : public ISplitter{
    //...
};

class TxtSplitter: public ISplitter{
    //...
};

class PictureSplitter: public ISplitter{
    //...
};

class VideoSplitter: public ISplitter{
    //...
};

// 每个具体类对应一个具体工厂, 用于生产其对象
class BinarySplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new BinarySplitter();
    }
};

class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new TxtSplitter();
    }
};

class PictureSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new PictureSplitter();
    }
};

class VideoSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new VideoSplitter();
    }
};

