#ifndef TELEGRAM_LOGOUT_H
#define TELEGRAM_LOGOUT_H

#include "fakepasscode/action.h"
#include "fakepasscode/multiaccount_action.h"

#include "base/flat_map.h"

namespace FakePasscode {
    class LogoutAction : public Action {
    public:
        static constexpr ActionType Kind = ActionType::Logout;

        LogoutAction() = default;
        explicit LogoutAction(QByteArray inner_data);

        void Execute() override;

        QByteArray Serialize() const override;

        ActionType GetType() const override;

        void SetLogout(qint32 index, bool logout);

        const base::flat_map<qint32, bool>& GetLogout() const;

        bool IsLogout(qint32 index) const;
        bool IsAnyLogout() const;

        void SubscribeOnLoggingOut();

        void Prepare() override;

    private:
        base::flat_map<qint32, bool> index_to_logout_;

        rpl::lifetime lifetime_;
        rpl::lifetime sub_lifetime_;

        void SubscribeOnAccountsChanges();
    };
}
#endif //TELEGRAM_LOGOUT_H
