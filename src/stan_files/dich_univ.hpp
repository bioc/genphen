/*
    genphen is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    genphen is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with genphen.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.1

#include <stan/model/model_header.hpp>

namespace model_dich_univ_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_dich_univ");
    reader.add_event(21, 19, "end", "model_dich_univ");
    return reader;
}

#include <meta_header.hpp>
 class model_dich_univ : public prob_grad {
private:
    int Z;
    vector<int> N;
    vector<int> Y;
    vector_d X;
public:
    model_dich_univ(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_dich_univ(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_dich_univ_namespace::model_dich_univ";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "Z", "int", context__.to_vec());
            Z = int(0);
            vals_i__ = context__.vals_i("Z");
            pos__ = 0;
            Z = vals_i__[pos__++];
            current_statement_begin__ = 4;
            validate_non_negative_index("N", "Z", Z);
            context__.validate_dims("data initialization", "N", "int", context__.to_vec(Z));
            validate_non_negative_index("N", "Z", Z);
            N = std::vector<int>(Z,int(0));
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            size_t N_limit_0__ = Z;
            for (size_t i_0__ = 0; i_0__ < N_limit_0__; ++i_0__) {
                N[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 5;
            validate_non_negative_index("Y", "Z", Z);
            context__.validate_dims("data initialization", "Y", "int", context__.to_vec(Z));
            validate_non_negative_index("Y", "Z", Z);
            Y = std::vector<int>(Z,int(0));
            vals_i__ = context__.vals_i("Y");
            pos__ = 0;
            size_t Y_limit_0__ = Z;
            for (size_t i_0__ = 0; i_0__ < Y_limit_0__; ++i_0__) {
                Y[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("X", "Z", Z);
            context__.validate_dims("data initialization", "X", "vector_d", context__.to_vec(Z));
            validate_non_negative_index("X", "Z", Z);
            X = vector_d(static_cast<Eigen::VectorXd::Index>(Z));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_i_vec_lim__ = Z;
            for (size_t i_vec__ = 0; i_vec__ < X_i_vec_lim__; ++i_vec__) {
                X[i_vec__] = vals_r__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 3;
            current_statement_begin__ = 4;
            current_statement_begin__ = 5;
            current_statement_begin__ = 6;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 10;
            ++num_params_r__;
            current_statement_begin__ = 11;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_dich_univ() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("alpha")))
            throw std::runtime_error("variable alpha missing");
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "alpha", "double", context__.to_vec());
        double alpha(0);
        alpha = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable alpha: ") + e.what());
        }

        if (!(context__.contains_r("beta")))
            throw std::runtime_error("variable beta missing");
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        context__.validate_dims("initialization", "beta", "double", context__.to_vec());
        double beta(0);
        beta = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(beta);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable beta: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            local_scalar_t__ alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.scalar_constrain(lp__);
            else
                alpha = in__.scalar_constrain();

            local_scalar_t__ beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.scalar_constrain(lp__);
            else
                beta = in__.scalar_constrain();


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body

            current_statement_begin__ = 16;
            lp_accum__.add(binomial_logit_log<propto__>(Y, N, add(alpha,multiply(beta,X))));
            current_statement_begin__ = 17;
            lp_accum__.add(student_t_log<propto__>(alpha, 1, 0, 100));
            current_statement_begin__ = 18;
            lp_accum__.add(student_t_log<propto__>(beta, 1, 0, 10));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha");
        names__.push_back("beta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_dich_univ_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double alpha = in__.scalar_constrain();
        double beta = in__.scalar_constrain();
        vars__.push_back(alpha);
        vars__.push_back(beta);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {



            // validate transformed parameters

            // write transformed parameters
            if (include_tparams__) {
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_dich_univ";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "beta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "beta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_dich_univ_namespace::model_dich_univ stan_model;


#endif
