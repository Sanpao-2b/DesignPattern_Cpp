
//抽象类
class ISplitter{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};


// 新增工厂基类 -- 替代new创建对象
class SplitterFactory{
public:
    virtual ISplitter* CreateSplitter()=0;  // 因此提供一个返回ISplitter的 对象创建方法
    virtual ~SplitterFactory(){}
};
