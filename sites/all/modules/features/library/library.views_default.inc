<?php
/**
 * @file
 * library.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function library_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'issue_return_a_book';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Issue a book';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Issue a book';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_book_node']['id'] = 'reverse_field_book_node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['field'] = 'reverse_field_book_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  /* Field: SUM(Content: No. of Copies) */
  $handler->display->display_options['fields']['field_no_of_copies']['id'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['table'] = 'field_data_field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['field'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['relationship'] = 'reverse_field_book_node';
  $handler->display->display_options['fields']['field_no_of_copies']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_no_of_copies']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_abaa' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_issue' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'issue-return-a-book';
  $export['issue_return_a_book'] = $view;

  $view = new view();
  $view->name = 'issue_return_table';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Issue/Return Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Books Currently Issued';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: User */
  $handler->display->display_options['fields']['field_user']['id'] = 'field_user';
  $handler->display->display_options['fields']['field_user']['table'] = 'field_data_field_user';
  $handler->display->display_options['fields']['field_user']['field'] = 'field_user';
  $handler->display->display_options['fields']['field_user']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issue Date */
  $handler->display->display_options['fields']['field_issue_date']['id'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['table'] = 'field_data_field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['field'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Return Date */
  $handler->display->display_options['fields']['field_return_date']['id'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['table'] = 'field_data_field_return_date';
  $handler->display->display_options['fields']['field_return_date']['field'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['label'] = 'Return By';
  $handler->display->display_options['fields']['field_return_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_return_by_librarian' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_options']['argument'] = 'Issued';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'issue-return-table';
  $export['issue_return_table'] = $view;

  $view = new view();
  $view->name = 'issue_return_table_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Issue/Return Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Issued Books';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Content: Issue Date */
  $handler->display->display_options['fields']['field_issue_date']['id'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['table'] = 'field_data_field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['field'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Return Date */
  $handler->display->display_options['fields']['field_return_date']['id'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['table'] = 'field_data_field_return_date';
  $handler->display->display_options['fields']['field_return_date']['field'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['label'] = 'Return By';
  $handler->display->display_options['fields']['field_return_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_options']['argument'] = 'Issued';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'issue-return-table-user';
  $export['issue_return_table_user'] = $view;

  $view = new view();
  $view->name = 'return_a_book';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Return a Book';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Return a Book';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issue Date */
  $handler->display->display_options['fields']['field_issue_date']['id'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['table'] = 'field_data_field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['field'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Return Date */
  $handler->display->display_options['fields']['field_return_date']['id'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['table'] = 'field_data_field_return_date';
  $handler->display->display_options['fields']['field_return_date']['field'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['label'] = 'Return By';
  $handler->display->display_options['fields']['field_return_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_issue_fields' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Return',
    ),
  );
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_options']['argument'] = 'Issued';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'return-a-book';
  $export['return_a_book'] = $view;

  $view = new view();
  $view->name = 'return_history';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Return History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Return History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: User */
  $handler->display->display_options['fields']['field_user']['id'] = 'field_user';
  $handler->display->display_options['fields']['field_user']['table'] = 'field_data_field_user';
  $handler->display->display_options['fields']['field_user']['field'] = 'field_user';
  $handler->display->display_options['fields']['field_user']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Content: Return Date */
  $handler->display->display_options['fields']['field_return_date']['id'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['table'] = 'field_data_field_return_date';
  $handler->display->display_options['fields']['field_return_date']['field'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Fine */
  $handler->display->display_options['fields']['field_fine']['id'] = 'field_fine';
  $handler->display->display_options['fields']['field_fine']['table'] = 'field_data_field_fine';
  $handler->display->display_options['fields']['field_fine']['field'] = 'field_fine';
  $handler->display->display_options['fields']['field_fine']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_options']['argument'] = 'Returned';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'return-history';
  $export['return_history'] = $view;

  $view = new view();
  $view->name = 'return_history_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Return History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Return History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Content: Return Date */
  $handler->display->display_options['fields']['field_return_date']['id'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['table'] = 'field_data_field_return_date';
  $handler->display->display_options['fields']['field_return_date']['field'] = 'field_return_date';
  $handler->display->display_options['fields']['field_return_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Fine */
  $handler->display->display_options['fields']['field_fine']['id'] = 'field_fine';
  $handler->display->display_options['fields']['field_fine']['table'] = 'field_data_field_fine';
  $handler->display->display_options['fields']['field_fine']['field'] = 'field_fine';
  $handler->display->display_options['fields']['field_fine']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_options']['argument'] = 'Returned';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'return-history-user';
  $export['return_history_user'] = $view;

  $view = new view();
  $view->name = 'top_5_books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Top 4 Books';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top 4 Books';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Rating */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'average',
  );
  /* Sort criterion: Content: Rating (field_rating:rating) */
  $handler->display->display_options['sorts']['field_rating_rating']['id'] = 'field_rating_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['field'] = 'field_rating_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'top-4-books';
  $export['top_5_books'] = $view;

  $view = new view();
  $view->name = 'top_available_books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Top Available Books';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top Available Books';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_book_node']['id'] = 'reverse_field_book_node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['field'] = 'reverse_field_book_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_image']['group_columns'] = array(
    'entity_type' => 'entity_type',
  );
  /* Field: SUM(Content: No. of Copies) */
  $handler->display->display_options['fields']['field_no_of_copies']['id'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['table'] = 'field_data_field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['field'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['relationship'] = 'reverse_field_book_node';
  $handler->display->display_options['fields']['field_no_of_copies']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_no_of_copies']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_no_of_copies']['group_column'] = 'entity_id';
  /* Sort criterion: SUM(Content: No. of Copies (field_no_of_copies)) */
  $handler->display->display_options['sorts']['field_no_of_copies_value']['id'] = 'field_no_of_copies_value';
  $handler->display->display_options['sorts']['field_no_of_copies_value']['table'] = 'field_data_field_no_of_copies';
  $handler->display->display_options['sorts']['field_no_of_copies_value']['field'] = 'field_no_of_copies_value';
  $handler->display->display_options['sorts']['field_no_of_copies_value']['relationship'] = 'reverse_field_book_node';
  $handler->display->display_options['sorts']['field_no_of_copies_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_no_of_copies_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'top-available-books';
  $export['top_available_books'] = $view;

  $view = new view();
  $view->name = 'transaction_table';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Transaction Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Transaction Table';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: User */
  $handler->display->display_options['fields']['field_user']['id'] = 'field_user';
  $handler->display->display_options['fields']['field_user']['table'] = 'field_data_field_user';
  $handler->display->display_options['fields']['field_user']['field'] = 'field_user';
  /* Field: Content: Book */
  $handler->display->display_options['fields']['field_book']['id'] = 'field_book';
  $handler->display->display_options['fields']['field_book']['table'] = 'field_data_field_book';
  $handler->display->display_options['fields']['field_book']['field'] = 'field_book';
  /* Field: Content: No. of Copies */
  $handler->display->display_options['fields']['field_no_of_copies']['id'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['table'] = 'field_data_field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['field'] = 'field_no_of_copies';
  /* Field: Content: Transaction Date */
  $handler->display->display_options['fields']['field_transaction_date']['id'] = 'field_transaction_date';
  $handler->display->display_options['fields']['field_transaction_date']['table'] = 'field_data_field_transaction_date';
  $handler->display->display_options['fields']['field_transaction_date']['field'] = 'field_transaction_date';
  /* Field: Content: Transaction Type */
  $handler->display->display_options['fields']['field_transaction_type']['id'] = 'field_transaction_type';
  $handler->display->display_options['fields']['field_transaction_type']['table'] = 'field_data_field_transaction_type';
  $handler->display->display_options['fields']['field_transaction_type']['field'] = 'field_transaction_type';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Filter criterion: Content: Transaction Type (field_transaction_type) */
  $handler->display->display_options['filters']['field_transaction_type_tid']['id'] = 'field_transaction_type_tid';
  $handler->display->display_options['filters']['field_transaction_type_tid']['table'] = 'field_data_field_transaction_type';
  $handler->display->display_options['filters']['field_transaction_type_tid']['field'] = 'field_transaction_type_tid';
  $handler->display->display_options['filters']['field_transaction_type_tid']['value'] = array(
    23 => '23',
  );
  $handler->display->display_options['filters']['field_transaction_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_transaction_type_tid']['expose']['operator_id'] = 'field_transaction_type_tid_op';
  $handler->display->display_options['filters']['field_transaction_type_tid']['expose']['label'] = 'Transaction Type';
  $handler->display->display_options['filters']['field_transaction_type_tid']['expose']['operator'] = 'field_transaction_type_tid_op';
  $handler->display->display_options['filters']['field_transaction_type_tid']['expose']['identifier'] = 'field_transaction_type_tid';
  $handler->display->display_options['filters']['field_transaction_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_transaction_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_transaction_type_tid']['vocabulary'] = 'issue_return';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'transaction-table';
  $export['transaction_table'] = $view;

  $view = new view();
  $view->name = 'view_all_the_books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'View all the books';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'View all the books';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_author' => 'field_author',
    'field_genre' => 'field_genre',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_genre' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_book_node']['id'] = 'reverse_field_book_node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_book_node']['field'] = 'reverse_field_book_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  /* Field: Content: Genre */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'field_data_field_genre';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  /* Field: SUM(Content: No. of Copies) */
  $handler->display->display_options['fields']['field_no_of_copies']['id'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['table'] = 'field_data_field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['field'] = 'field_no_of_copies';
  $handler->display->display_options['fields']['field_no_of_copies']['relationship'] = 'reverse_field_book_node';
  $handler->display->display_options['fields']['field_no_of_copies']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_no_of_copies']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_add_stock' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_delete_stock' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_issue_librarian_1' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Issue to a user',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'view';
  $export['view_all_the_books'] = $view;

  return $export;
}
