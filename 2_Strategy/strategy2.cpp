

// �������(�ӿ���)
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};



//��չ ������չ
//*********************************
class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};

// ���������ͷǳ��ȶ�
class SalesOrder{
private:
    TaxStrategy* strategy;      // ������һ���ӿ�(��Ϸ�ʽ),����ӿ���һ���������ָ��, ����ʱָ��һ�������˰��(����ʱ����)
    // strategyFactory* factory;     // ����Ҫ
public:
    // ��Ϊ���������һ�� TaxStrategy�麯��ָ��, ����Ҫ������ֵ, �����ֱ�� strategy = new "������ҵ�˰����", �������һ������ʱ����, new����Ķ����Ǳ仯��!
    // ����ģʽ---- ������󴴽� �������ı���ʱ��������!
    //        ---- ���˹���ģʽ��, �����������ﵽһ�����ȶ�״̬, ������Ҫ����ʲô���ҵ�˰, �������ٹ���, �����SalesOrder�඼����������
    //        ---- ������Ĺ���������ͬ����, ���ﲻ��Ҫӵ��һ����������ָ���Ա����, ֱ�ӹ��캯������ô������ľ�������ʵ����strategy��
    SalesOrder(StrategyFactory* strategyFactory){
        //strategy = strategyFactory;
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    public double CalculateTax(){           // ���calculate����, �������������ֹ���, �����øı� ���������SalesOrder �����øı� �ǳ��ȶ�
        //...
        Context context();
        
        double val = strategy->Calculate(context); //��̬����
        //...
    }
    
};


int main()
{

    // ��Ҫ���㷨����˰, ���뷨��
    SalesOrder so(FRTax);
    so.
    return 0;
}
