<?php
/**
 * @file
 * library.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function library_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-librarian-menu_add-book:node/add/book.
  $menu_links['menu-librarian-menu_add-book:node/add/book'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'node/add/book',
    'router_path' => 'node/add/book',
    'link_title' => 'Add Book',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_add-book:node/add/book',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_add-user:admin/people/create.
  $menu_links['menu-librarian-menu_add-user:admin/people/create'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'admin/people/create',
    'router_path' => 'admin/people/create',
    'link_title' => 'Add User',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_add-user:admin/people/create',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_fine:details.
  $menu_links['menu-librarian-menu_fine:details'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'details',
    'router_path' => 'details',
    'link_title' => 'Fine',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_fine:details',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_view-currently-issued-books:issue-return-table.
  $menu_links['menu-librarian-menu_view-currently-issued-books:issue-return-table'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'issue-return-table',
    'router_path' => 'issue-return-table',
    'link_title' => 'View Currently Issued Books',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_view-currently-issued-books:issue-return-table',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_view-return-history:return-history.
  $menu_links['menu-librarian-menu_view-return-history:return-history'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'return-history',
    'router_path' => 'return-history',
    'link_title' => 'View Return History',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_view-return-history:return-history',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_view-the-books:view.
  $menu_links['menu-librarian-menu_view-the-books:view'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'view',
    'router_path' => 'view',
    'link_title' => 'View the books',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_view-the-books:view',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-librarian-menu_view-the-transaction-table:transaction-table.
  $menu_links['menu-librarian-menu_view-the-transaction-table:transaction-table'] = array(
    'menu_name' => 'menu-librarian-menu',
    'link_path' => 'transaction-table',
    'router_path' => 'transaction-table',
    'link_title' => 'View the Transaction Table',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-librarian-menu_view-the-transaction-table:transaction-table',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-user_issue-a-book:issue-return-a-book.
  $menu_links['menu-user_issue-a-book:issue-return-a-book'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'issue-return-a-book',
    'router_path' => 'issue-return-a-book',
    'link_title' => 'Issue a book',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_issue-a-book:issue-return-a-book',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-user_return-a-book:return-a-book.
  $menu_links['menu-user_return-a-book:return-a-book'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'return-a-book',
    'router_path' => 'return-a-book',
    'link_title' => 'Return a book',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_return-a-book:return-a-book',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-user_view-currently-issued-books:issue-return-table-user.
  $menu_links['menu-user_view-currently-issued-books:issue-return-table-user'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'issue-return-table-user',
    'router_path' => 'issue-return-table-user',
    'link_title' => 'View Currently Issued Books',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_view-currently-issued-books:issue-return-table-user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-user_view-profile:user.
  $menu_links['menu-user_view-profile:user'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'View Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_view-profile:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-user_view-return-history:return-history-user.
  $menu_links['menu-user_view-return-history:return-history-user'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'return-history-user',
    'router_path' => 'return-history-user',
    'link_title' => 'View Return History',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_view-return-history:return-history-user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-user_view-the-books:view.
  $menu_links['menu-user_view-the-books:view'] = array(
    'menu_name' => 'menu-user',
    'link_path' => 'view',
    'router_path' => 'view',
    'link_title' => 'View the Books',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user_view-the-books:view',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: navigation_add-content:node/add.
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Book');
  t('Add User');
  t('Add content');
  t('Fine');
  t('Issue a book');
  t('Return a book');
  t('View Currently Issued Books');
  t('View Profile');
  t('View Return History');
  t('View the Books');
  t('View the Transaction Table');
  t('View the books');

  return $menu_links;
}
