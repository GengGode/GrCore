//
// Created by YuSuiXian on 2023/5/3.
//

#ifndef GRCORE_RESULT_H
#define GRCORE_RESULT_H

// std
#ifndef STD_VARIANT_INCLUDE
#define STD_VARIANT_INCLUDE
#include <variant>
#endif
#ifndef STD_STRING_INCLUDE
#define STD_STRING_INCLUDE
#include <string>
#endif

namespace Gr {
    namespace Core {

        class Error
        {
        public:
            Error() = default;
            Error(int err_code, const std::string& err_msg) : m_err_code(err_code), m_err_msg(err_msg) {}
            Error(int err_code, const char * err_msg) : m_err_code(err_code), m_err_msg(err_msg) {}
        public:
            int get_err_code() const { return m_err_code; }
            std::string get_err_msg() const { return m_err_msg; }
        private:
            int         m_err_code = 0;
            std::string m_err_msg  = "";
        };
        template<typename T, typename F>
        class Result {
            std::variant<T, F> m_result;
        public:
            Result(T value) : m_result(value) {}
            Result(F error) : m_result(error) {}
            bool is_ok() const { return std::holds_alternative<T>(m_result); }
            bool is_err() const { return std::holds_alternative<F>(m_result); }
            T unwrap() const { return std::get<T>(m_result); }
            F unwrap_err() const { return std::get<F>(m_result); }
            // map
            template<typename U>
            Result<U, F> map(std::function<U(T)> func) const {
                if (is_ok()) {
                    return Result<U, F>(func(unwrap()));
                }
                else {
                    return Result<U, F>(unwrap_err());
                }
            }
            // match
            template<typename U>
            U match(std::function<U(T)> ok_func, std::function<U(F)> err_func) const {
                if (is_ok()) {
                    return ok_func(unwrap());
                }
                else {
                    return err_func(unwrap_err());
                }
            }
            // bind
            template<typename U>
            Result<U, F> bind(std::function<Result<U, F>(T)> func) const {
                if (is_ok()) {
                    return func(unwrap());
                }
                else {
                    return Result<U, F>(unwrap_err());
                }
            }
        };

        // T, Error
        template<typename T>
        using Res = Result<T, Error>;

        using Err = Error;


    } // Gr
} // Core


#endif //GRCORE_RESULT_H
