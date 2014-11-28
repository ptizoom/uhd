//
// Copyright 2014 Ettus Research LLC
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INCLUDED_TEST_GRAPH_HPP
#define INCLUDED_TEST_GRAPH_HPP

#include <uhd/usrp/rfnoc/node_ctrl_base.hpp>
#include <uhd/usrp/rfnoc/sink_node_ctrl.hpp>
#include <uhd/usrp/rfnoc/source_node_ctrl.hpp>

#define MAKE_NODE(name) test_node::sptr name(new test_node(#name));

// Smallest possible test class
class test_node : virtual public uhd::rfnoc::sink_node_ctrl, virtual public uhd::rfnoc::source_node_ctrl
{
public:
    typedef boost::shared_ptr<test_node> sptr;

    test_node(const std::string &test_id) : _test_id(test_id) {};

    void issue_stream_cmd(const uhd::stream_cmd_t &) {/* nop */};

    std::string get_test_id() const { return _test_id; };

private:
    const std::string _test_id;

}; /* class test_node */

void connect_nodes(uhd::rfnoc::node_ctrl_base::sptr A, uhd::rfnoc::node_ctrl_base::sptr B)
{
    A->register_downstream_node(B);
    B->register_upstream_node(A);
}

#endif /* INCLUDED_TEST_GRAPH_HPP */
// vim: sw=4 et:
