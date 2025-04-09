#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IEntity
{
    public:
    virtual void Save() = 0;
};

class AccountEntity : public IEntity
{
    public:
    void Save() override
    {
        cout << "The account type entity is saved" << endl;
        return;
    }
};

class RoleEntity : public IEntity
{
    public:
    void Save() override
    {
        cout << "The role type entity is saved" << endl;
        return;
    }
};

class Repository
{
    public:
    static void EntitySave(shared_ptr <IEntity> _entity)
    {
        _entity->Save();
        return;
    }

};

int main ()
{
    shared_ptr <AccountEntity> account = make_shared <AccountEntity>();
    shared_ptr <RoleEntity> role = make_shared <RoleEntity>();
    
    //(account)
    Repository::EntitySave(account);

    //(role)
    Repository::EntitySave(role);

    return 0;
}