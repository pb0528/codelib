#include<memory>

namespace DIY
{
    template <typename T>
    class auto_ptr
    {
    private:
        T* m_ptr; //被封装的指针
    public:
        autoptr(T* p):m_ptr(p){}
        ~auto_ptr()
        {
            delete m_ptr;
        }

        T& operator *()
        {
            return *m_ptr;
        }

        T* operator ->()
        {
            return m_ptr;
        }

    };
} // namespace DIY
